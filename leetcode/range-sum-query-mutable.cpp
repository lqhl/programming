#include "util.hpp"

inline int lowbit(int x) {
    return x & -x;
}

class NumArray {
private:
    int n;
    vector<int>& nums;
    vector<int> BIT;

    int sum(int i) {
        i++;
        int ans = 0;
        for (int j = i; j > 0; j -= lowbit(j))
            ans += BIT[j];
        return ans;
    }

public:
    NumArray(vector<int>& nums): n(nums.size()), nums(nums), BIT(n+1) {
        for (int i = 1; i <= n; i++) {
            BIT[i] = nums[i-1];
            int r = lowbit(i);
            for (int j = i-1; j > i-r; j--)
                BIT[i] += nums[j-1];
        }
    }

    void update(int i, int val) {
        int delta = val - nums[i];
        nums[i] = val;
        i++;
        for (int j = i; j <= n; j += lowbit(j))
            BIT[j] += delta;
    }

    int sumRange(int i, int j) {
        return sum(j) - sum(i-1);
    }
};

// Segment Tree
class NumArray2 {
private:
    int n;
    vector<int>& nums;
    vector<int> tree;

    void build(int cur, int x, int y) {
        if (x > y)
            return;
        if (x == y) {
            tree[cur] = nums[x];
            return;
        }
        build(cur*2+1, x, (x+y)>>1);
        build(cur*2+2, ((x+y)>>1)+1, y);
        tree[cur] = tree[cur*2+1]+tree[cur*2+2];
    }

    void update(int cur, int x, int y, int i, int val) {
        if (x > y || i < x || i > y)
            return;
        if (x == y) {
            tree[cur] = val;
            return;
        }
        update(cur*2+1, x, (x+y)>>1, i, val);
        update(cur*2+2, ((x+y)>>1)+1, y, i, val);
        tree[cur] = tree[cur*2+1]+tree[cur*2+2];
    }

    int query(int cur, int x, int y, int i, int j) {
        if (x > y || y < i || x > j)
            return 0;
        if (i <= x && j >= y)
            return tree[cur];
        return query(cur*2+1, x, (x+y)>>1, i, j) + query(cur*2+2, ((x+y)>>1)+1, y, i, j);
    }

public:
    NumArray2(vector<int> &nums): n(nums.size()), nums(nums), tree(4*n) {
        build(0, 0, n-1);
    }

    void update(int i, int val) {
        update(0, 0, n-1, i, val);
    }

    int sumRange(int i, int j) {
        return query(0, 0, n-1, i, j);
    }
};

int main() {
    vector<int> nums = {1, 3, 5};
    NumArray q(nums);
    cout << q.sumRange(0, 2) << endl;
    q.update(1, 2);
    cout << q.sumRange(0, 2) << endl;
}
