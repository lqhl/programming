/*
 * Problem  : 371D - Vessels
 * Site     : Codeforces
 * Category : Data Structure - Binary Tree
 * Status   : AC
 * Author   : Qin Liu (lqgy2001@gmail.com)
 * Date     : 2013-12-12
 * Remark   : N/A
 */
#include <stdio.h>
#include <stdint.h>
#include <set>

#define MAX_N 200000

int left[MAX_N], cap[MAX_N];
std::set<int> vessels;

void update(int p, int x) {
    std::set<int>::iterator it = vessels.upper_bound(p);
    if (it == vessels.end())
        return;

    p = *it;
    if (left[p] <= x) {
        x -= left[p];
        left[p] = 0;
        vessels.erase(it);
        if (x > 0)
            update(p, x);
    } else
        left[p] -= x;
}

int main() {
    int n, m;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &left[i]);
        cap[i] = left[i];
        if (left[i] > 0)
            vessels.insert(i);
    }

    scanf("%d", &m);
    for (; m > 0; m--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int p, x;
            scanf("%d%d", &p, &x);
            p--;
            update(p - 1, x);
            //for (int i = 0; i < n; i++)
                //printf("vessel %d: %d\n", i, left[i]);
        } else { // if (type == 2)
            int k;
            scanf("%d", &k);
            k--;
            printf("%d\n", cap[k] - left[k]);
        }
    }

    return 0;
}
