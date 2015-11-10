#include "util.hpp"

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct cmp {
    bool operator()(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
};
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp());
        if (intervals.size() <= 1)
            return intervals;
        vector<Interval> res;
        Interval last = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
            if (last.end < intervals[i].start) {
                res.push_back(last);
                last = intervals[i];
            } else {
                last.end = max(last.end, intervals[i].end);
            }
        res.push_back(last);
        return res;
    }
};
