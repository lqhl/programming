#include <iostream>
#include <math.h>

using namespace std;

int solve(long long K) {
    if ((K & (K - 1)) == 0)
        return 0;
    long long next = pow(2, ceil(log(K)/log(2)));
    long long half = next / 2;
    K = half - (K - half);
    return 1 - solve(K);
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        long long K;
        cin >> K;
        cout << "Case #" << i << ": " << solve(K) << endl;
    }
}
