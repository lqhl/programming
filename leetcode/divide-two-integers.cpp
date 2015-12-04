#include "util.hpp"

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)
            return INT_MAX;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        long long a = dividend, b = divisor;
        int sign = 1;
        if (a < 0) {
            a = -a;
            sign = -sign;
        }
        if (b < 0) {
            b = -b;
            sign = -sign;
        }
        
        int result = 0;
        while (a >= b) {
            int c = 0;
            while (a >= (b<<c)) c++;
            c--;
            result += 1<<c;
            a -= b<<c;
        }
        return sign*result;
    }
};
