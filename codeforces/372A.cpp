/*
 * Problem  : 372A - Counting Kangaroos is Fun
 * Site     : Codeforces
 * Category : Binary Search
 * Status   : AC
 * Author   : Qin Liu (lqgy2001@gmail.com)
 * Date     : 2013-12-14
 * Remark   : N/A
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <algorithm>

#define MAX_N 500000
int n;
int d[MAX_N];

bool avalible(int k) {
    for (int i = k; i < n; i++)
        if (d[i - k] * 2 > d[i])
            return false;
    return true;
}

int binary_search(int left, int right) {
    //printf("left: %d, right: %d\n", left, right);
    if (left == right)
        return left;
    int mid = (left + right) / 2;
    if (avalible(mid))
        return binary_search(left, mid);
    else
        return binary_search(mid + 1, right);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", d + i);
    std::sort(d, d + n);
    int k = binary_search(n / 2, n);
    printf("%d\n", k >= n - k ? k : n - k);
}
