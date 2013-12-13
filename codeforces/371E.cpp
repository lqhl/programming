/*
 * Problem  : 371E - Subway Innovation
 * Site     : Codeforces
 * Category : DP
 * Status   : AC
 * Author   : Qin Liu (lqgy2001@gmail.com)
 * Date     : 2013-12-09
 * Remark   : Use int64 to handle large numbers.
 */
#include <stdio.h>
#include <algorithm>
#include <stdint.h>

#define MAX_N 300010

typedef struct {
    int data;
    int num;
} elem_t;

elem_t d[MAX_N];
int64_t sum[MAX_N];

bool cmp(elem_t a, elem_t b) {
    return a.data < b.data;
}

int main() {
    int n, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i].data);
        d[i].num = i + 1;
    }
    scanf("%d", &k);

    std::sort(d, d + n, cmp);

    sum[0] = d[0].data;
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + d[i].data;
    }

    uint64_t f = 0;
    for (int i = 1; i < k; i++)
        f += ((int64_t) d[i].data * i - sum[i - 1]);

    int min_ind = 0;
    uint64_t min = f;
    for (int i = 0; i < n - k; i++) {
        f += ((k - 1) * (int64_t) (d[i + k].data + d[i].data) - 2 * (sum[i + k - 1] - sum[i]));
        if (f < min) {
            min_ind = i + 1;
            min = f;
        }
    }

    for (int i = min_ind; i < min_ind + k; i++)
        printf("%d ", d[i].num);
    printf("\n");

    return 0;
}
