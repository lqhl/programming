/*
 * Contest: Google APAC 2016 University Graduates Test - Round C
 * Problem: gMatrix
 * Author: Qin Liu
 *
 * Tag: data structure
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
int M[Max][Max];
int P[Max][Max];

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

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                M[i][j] = (int) ((A[i] * (i+1) + B[j] * (j+1) + C) % X);

        for (int i = 0; i < N; i++) {
            deque<int> q;
            for (int j = 0; j < N; j++) {
                while (!q.empty() && M[i][q.back()] <= M[i][j])
                    q.pop_back();
                q.push_back(j);
                if (q.front() + K <= j)
                    q.pop_front();
                if (j >= K-1)
                    P[i][j] = M[i][q.front()];
            }
        }

        long long sum = 0;
        for (int j = K-1; j < N; j++) {
            deque<int> q;
            for (int i = 0; i < N; i++) {
                while (!q.empty() && P[q.back()][j] <= P[i][j])
                    q.pop_back();
                q.push_back(i);
                if (q.front() + K <= i)
                    q.pop_front();
                if (i >= K-1) {
                    sum += P[q.front()][j];
                }
            }
        }

        cout << sum << endl;

    }
    return 0;
}
