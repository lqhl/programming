/*
 * Problem  : 135A - Replacement
 * Site     : Codeforces
 * Category : Sort
 * Status   : AC
 * Author   : Qin Liu (lqgy2001@gmail.com)
 * Date     : 2013-12-13
 * Remark   : Since testcases include anti quicksort, we must use a random
 *            pivot.
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int d[MAX_N];

template <class T>
void quicksort(T d[], int left, int right) {
    int l = left, r = right;
    T vp = d[l + rand() % (r - l + 1)];
    do {
        while (d[l] < vp) l++;
        while (d[r] > vp) r--;
        if (l <= r) {
            T tmp = d[r];
            d[r] = d[l];
            d[l] = tmp;
            l++;
            r--;
        }
    } while (l <= r);
    if (left < r)
        quicksort(d, left, r);
    if (l < right)
        quicksort(d, l, right);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &d[i]);

    int k = 0;
    for (int i = 1; i < n; i++)
        if (d[i] > d[k])
            k = i;
    if (d[k] == 1)
        d[k] = 2;
    else
        d[k] = 1;

    quicksort(d, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", d[i]);
    printf("\n");
}
