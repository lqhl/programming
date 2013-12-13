/*
 * Title    : Quick Sort
 * Status   : Tested with 135A
 * Author   : Qin Liu (lqgy2001@gmail.com)
 * Date     : 2013-12-13
 * Remark   : speed: std::sort > quicksort > qsort > selectsort
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

inline int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

template <class T>
void selectsort(T d[], int left, int right) {
    for (int i = left; i < right; i++) {
        T min = d[i];
        int k = i;
        for (int j = i + 1; j <= right; j++)
            if (d[j] < min) {
                min = d[j];
                k = j;
            }
        if (i != k) {
            T tmp = d[i];
            d[i] = d[k];
            d[k] = tmp;
        }
    }
}

template <class T>
void quicksort(T d[], int left, int right) {
    int l = left, r = right;
    T vp = d[(l + r) / 2];
    // random pivot
    //T vp = d[l + rand() % (r - l + 1)];
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

template <class T>
int quickselect(T d[], int left, int right, int k) {
    if (left == right)
        return d[left];
    int l = left, r = right;
    T vp = d[(l + r) / 2];
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
    if (k <= r)
        return quickselect(d, left, r, k);
    else if (k >= l)
        return quickselect(d, l, right, k);
    else
        return d[k];
}

int main() {
    //srand(time(NULL));
    int n = 3000;
    int *d = new int[n];
    for (int i = 0; i < n; i++)
        d[i] = rand();
    int k = rand() % n;
    printf("%dth: %d\n", k, quickselect(d, 0, n - 1, k));
    //selectsort(d, 0, n - 1);
    //qsort(d, n, sizeof(*d), cmp);
    quicksort(d, 0, n - 1);
    //std::sort(d, d + n);
    printf("%dth: %d\n", k, d[k]);
    delete []d;
}
