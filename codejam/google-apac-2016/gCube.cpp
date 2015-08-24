#include <iostream>
#include <math.h>

using namespace std;

double d[2000];

int main() {
    int T;
    cin >> T;
    cout.precision(9);
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ":" << endl;
        int N, M;
        cin >> N >> M;
        for (int j = 0; j < N; j++)
            cin >> d[j];
        for (int j = 0; j < M; j++) {
            int s, t;
            cin >> s >> t;
            double volume = 1.0;
            double len = t - s + 1;
            for (int j = s; j <= t; j++)
                volume *= pow(d[j], 1 / len);
            cout << fixed << volume << endl;
        }
    }
}
