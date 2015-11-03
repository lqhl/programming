#include "util.hpp"

/*
 * Definition for a point.
 */
struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() < 3)
            return points.size();
        int res = 0;
        for (size_t i = 0; i < points.size(); i++) {
            int dup = 1;
            int vert = 0;
            map<double, int> slopes;
            for (size_t j = i+1; j < points.size(); j++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    dup++;
                    continue;
                }
                if (points[i].x == points[j].x) {
                    vert++;
                    continue;
                }
                double s = (double) (points[i].y-points[j].y) / (points[i].x-points[j].x);
                slopes[s]++;
            }
            int count = 0;
            for (auto& kv : slopes) {
                if (kv.second > count)
                    count = kv.second;
            }
            count = max(count, vert);
            count += dup;
            res = max(res, count);
        }
        return res;
    }
};
