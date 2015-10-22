/*
 * Contest: Google APAC 2016 University Graduates Test - Round C
 * Problem: gFiles
 * Author: Qin Liu
 *
 * Tag: math
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;
    cout.precision(9);
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        int N;
        cin >> N;
        long long all_low = 0, all_high = 1e15+1;
        for (int i = 0; i < N; i++) {
            long long low = 0, high = 1e15+1;
            long long P;
            long long K;

            cin >> P >> K;

            if (P == 100) {
                all_high = all_low = K;
                continue;
            }
            if (P > 0)
                high = K * 100 / P;
            if (P < 100)
                low = K * 100 / (P+1) + 1;

            /* cout << low << " " << high << endl; */
            all_low = max(all_low, low);
            all_high = min(all_high, high);
        }
        /* cout << all_low << " " << all_high << endl; */
        /* cout << ceil(all_low) << " " << floor(all_high) << endl; */
        if (all_low == all_high)
            cout << all_low << endl;
        else
            cout << -1 << endl;
    }
}
