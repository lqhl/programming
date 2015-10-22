/*
 * Contest: Google APAC 2016 University Graduates Test - Round C
 * Problem: gMatrix
 * Author: Qin Liu
 *
 * Tag: data structure, quad tree, 2D segment tree
 * Remark: This implementation of 2D segment tree is faster.
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <cmath>

using namespace std;

#define Max 3500
#define INF (1 << 30)

int roundup_pow2(int v) {
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    return ++v;
}

template<typename data_type>
class QuadTree {
protected:
    void build1D(int node2D, int node, int x, int y1, int y2) {
        if (y1 > y2)
            return;
        if (y1 == y2) {
            tree[node2D][node] = D[x][y1];
            return;
        }

        build1D(node2D, 2*node, x, y1, (y1+y2)>>1);
        build1D(node2D, 2*node+1, x, ((y1+y2)>>1)+1, y2);
        tree[node2D][node] = sum(tree[node2D][2*node], tree[node2D][2*node+1]);
    }

    void build2D(int node, int x1, int x2) {
        if (x1 > x2)
            return;
        if (x1 == x2) {
            build1D(node, 1, x1, 0, m-1);
            return;
        }

        build2D(2*node, x1, (x1+x2)>>1);
        build2D(2*node+1, ((x1+x2)>>1)+1, x2);
        for (int i = 0; i < M; i++)
            tree[node][i] = sum(tree[2*node][i], tree[2*node+1][i]);
    }

    data_type query1D(int node2D, int node, int y1, int y2, int qy1, int qy2) {
        if (y1 > y2 || y2 < qy1 || y1 > qy2)
            return zero();
        if (y1 >= qy1 && y2 <= qy2)
            return tree[node2D][node];

        data_type result = zero();
        result = sum(result, query1D(node2D, 2*node, y1, (y1+y2)>>1,
                    qy1, qy2));
        result = sum(result, query1D(node2D, 2*node+1, ((y1+y2)>>1)+1, y2,
                    qy1, qy2));
        return result;
    }

    data_type query2D(int node, int x1, int x2,
            int qx1, int qy1, int qx2, int qy2) {
        if (x1 > x2 || x2 < qx1 || x1 > qx2)
            return zero();
        if (x1 >= qx1 && x2 <= qx2)
            return query1D(node, 1, 0, m-1, qy1, qy2);

        data_type result = zero();
        result = sum(result, query2D(2*node, x1, (x1+x2)>>1,
                    qx1, qy1, qx2, qy2));
        result = sum(result, query2D(2*node+1, ((x1+x2)>>1)+1, x2,
                qx1, qy1, qx2, qy2));
        return result;
    }

    virtual data_type sum(const data_type& a, const data_type& b) = 0;
    virtual data_type zero() = 0;

    data_type** D;
    data_type** tree;
    int n, m;
    int N, M;

public:
    QuadTree(data_type** D, int n, int m): D(D), n(n), m(m) {
        N = 2 * roundup_pow2(n);
        M = 2 * roundup_pow2(m);
        tree = new data_type*[N];
        for (int i = 0; i < N; i++)
            tree[i] = new data_type[M];
    }

    ~QuadTree() {
        for (int i = 0; i < N; i++)
            delete[] tree[i];
        delete[] tree;
    }

    void build() {
        build2D(1, 0, n-1);
    }

    data_type query(int qx1, int qy1, int qx2, int qy2) {
        if (qx1 > qx2 || qy1 > qy2)
            return zero();
        return query2D(1, 0, n-1, qx1, qy1, qx2, qy2);
    }
};

class MaxQuadTree: public QuadTree<int> {
protected:
    int sum(const int& a, const int& b) {
        return max(a, b);
    }
    int zero() {
        return -INF;
    }
public:
    MaxQuadTree(int** D, int n, int m): QuadTree(D, n, m) {
    }
};

int main(void) {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        int N, K, C;
        long long X;

        cin >> N >> K >> C >> X;
        vector<long long> A(N), B(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int i = 0; i < N; i++)
            cin >> B[i];

        int** P = new int*[N];
        for(int i = 0; i < N; i++) {
            P[i] = new int[N];
            for(int j = 0; j < N; j++)
                P[i][j] = (A[i] * (i+1) + B[j] * (j+1) + C) % X;
        }

        MaxQuadTree qtree(P, N, N);
        qtree.build();

        long long sum = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                int ii = i + K - 1, jj = j + K - 1;
                if (ii < N && jj < N)
                    sum += qtree.query(i, j, ii, jj);
            }
        cout << sum << endl;

        for(int i = 0; i < N; i++)
            delete[] P[i];
        delete[] P;
    }
    return 0;
}
