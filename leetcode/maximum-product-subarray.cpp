#include "util.hpp"

inline int max(int a, int b) {
    return a >= b ? a : b;
}
inline int min(int a, int b) {
    return a <= b ? a : b;
}

class Solution {
public:
    int maxProduct(int A[], int n) {
        int max_all = A[0];
        int max_here = A[0];
        int min_here = A[0];

        for (int i = 1; i < n; i++) {
            if (A[i] >= 0) {
                max_here = max(max_here * A[i], A[i]);
                min_here = min(min_here * A[i], A[i]);
            } else {
                int max_here_old = max_here;
                max_here = max(min_here * A[i], A[i]);
                min_here = min(max_here_old * A[i], A[i]);
            }
            max_all = max(max_all, max_here);
        }

        return max_all;
    }
};

int main() {
    int A[] = {2,3,-2,4};
    Solution sol;
    printf("%d\n", sol.maxProduct(A, 4));
}
