#include "util.hpp"

class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        string results;
        if (numerator == 0)
            return "0";
        if ((numerator < 0) ^ (denominator < 0))
            results = "-";
        if (numerator < 0) numerator = -numerator;
        if (denominator < 0) denominator = -denominator;
        results += to_string(numerator / denominator);
        long long remainder = numerator % denominator;
        if (remainder == 0)
            return results;
        results.push_back('.');
        unordered_map<long long, int> visited;
        remainder *= 10;
        while (remainder != 0) {
            if (visited.count(remainder)) {
                int start = visited[remainder];
                results = results.substr(0, start) + "(" + results.substr(start) + ")";
                return results;
            }
            visited[remainder] = results.length();
            results.append(to_string(remainder / denominator));
            remainder = (remainder % denominator) * 10;
        }
        return results;
    }
};
