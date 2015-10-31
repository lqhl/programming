#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> results;
        bool inserted = false;
        Interval to_insert = newInterval;
        for (auto& each : intervals) {
            if (inserted)
                results.push_back(each);
            else {
                if (each.end < to_insert.start)
                    results.push_back(each);
                else if (to_insert.end < each.start) {
                    results.push_back(to_insert);
                    results.push_back(each);
                    inserted = true;
                } else {
                    to_insert = Interval(min(each.start, to_insert.start), max(each.end, to_insert.end));
                }
            }
        }
        if (!inserted)
            results.push_back(to_insert);
        return results;
    }
};
