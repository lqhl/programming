/*
 * Problem  : 371C - Hamburgers
 * Site     : Codeforces
 * Category : Binary Search
 * Status   : AC
 * Author   : Qin Liu (lqgy2001@gmail.com)
 * Date     : 2013-12-13
 * Remark   : N/A
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <iostream>

int64_t r;
int d[3], n[3], p[3];

inline int64_t max(int64_t a, int64_t b) {
    return a > b ? a : b;
}

bool avalible(int64_t x) {
    int64_t cost = 0;
    for (int i = 0; i < 3; i++)
        cost += max((int64_t) d[i] * x - (int64_t) n[i], 0LL) * p[i];
    return r >= cost;
}

int64_t binary_search(int64_t left, int64_t right) {
    if (left == right)
        return left;
    int64_t mid = (left + right + 1) / 2;
    if (avalible(mid))
        return binary_search(mid, right);
    else
        return binary_search(left, mid - 1);
}

int main() {
    char st[101];
    std::cin >> st;
    for (int i = 0; i < strlen(st); i++)
        switch (st[i]) {
            case 'B':
                d[0]++;
                break;
            case 'S':
                d[1]++;
                break;
            case 'C':
                d[2]++;
                break;
        }
    for (int i = 0; i < 3; i++)
        std::cin >> n[i];
    for (int i = 0; i < 3; i++)
        std::cin >> p[i];
    std::cin >> r;

    std::cout << binary_search(0LL, r + 101) << std::endl;
    return 0;
}
