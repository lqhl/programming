/*
 * Contest: Google APAC 2016 University Graduates Test - Round C
 * Problem: gMatrix
 * Author: Qin Liu
 *
 * Tag: data structure, quad tree, 2D segment tree
 * Remark: This implementation is too slow for large input.
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

template<typename data_type>
class QuadTree {
protected:
    data_type build(int node, int x1, int y1, int x2, int y2) {
        if (x1 > x2 || y1 > y2)
            return zero();
        if (x1 == x2 && y1 == y2)
            return tree[node] = D[x1][y1];

        tree[node] = zero();
        tree[node] = sum(tree[node], build(4*node-2, x1, y1, (x1+x2)>>1, (y1+y2)>>1));
        tree[node] = sum(tree[node], build(4*node-1, ((x1+x2)>>1)+1, ((y1+y2)>>1)+1, x2, y2));
        tree[node] = sum(tree[node], build(4*node-0, x1, ((y1+y2)>>1)+1, (x1+x2)>>1, y2));
        tree[node] = sum(tree[node], build(4*node+1, ((x1+x2)>>1)+1, y1, x2, (y1+y2)>>1));
        return tree[node];
    }

    data_type query(int node, int x1, int y1, int x2, int y2,
            int qx1, int qy1, int qx2, int qy2) {
        if (x1 > x2 || y1 > y2 || x2 < qx1 || y2 < qy1 || x1 > qx2 || y1 > qy2)
            return zero();
        if (x1 >= qx1 && y1 >= qy1 && x2 <= qx2 && y2 <= qy2)
            return tree[node];

        data_type result = zero();
        result = sum(result, query(4*node-2, x1, y1, (x1+x2)>>1, (y1+y2)>>1,
                qx1, qy1, qx2, qy2));
        result = sum(result, query(4*node-1, ((x1+x2)>>1)+1, ((y1+y2)>>1)+1, x2, y2,
                qx1, qy1, qx2, qy2));
        result = sum(result, query(4*node-0, x1, ((y1+y2)>>1)+1, (x1+x2)>>1, y2,
                qx1, qy1, qx2, qy2));
        result = sum(result, query(4*node+1, ((x1+x2)>>1)+1, y1, x2, (y1+y2)>>1,
                qx1, qy1, qx2, qy2));
        return result;
    }

    virtual data_type sum(const data_type& a, const data_type& b) = 0;
    virtual data_type zero() = 0;

    data_type** D;
    data_type* tree;
    int n, m;

public:
    QuadTree(data_type** D, int n, int m): D(D), n(n), m(m) {
        tree = new data_type[n*m*4+10];
    }

    ~QuadTree() {
        delete[] tree;
    }

    void build() {
        build(1, 0, 0, n-1, m-1);
    }

    data_type query(int qx1, int qy1, int qx2, int qy2) {
        if (qx1 > qx2 || qy1 > qy2)
            return zero();
        return query(1, 0, 0, n-1, m-1, qx1, qy1, qx2, qy2);
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
        int N, K, X, C;

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
                P[i][j] = (int) ((A[i] * (i+1) + B[j] * (j+1) + C) % X);
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
