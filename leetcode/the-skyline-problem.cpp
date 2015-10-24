#include <vector>
#include <map>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
private:
    struct Comparator{
        vector<vector<int>>& buildings;
        Comparator(vector<vector<int>>& buildings): buildings(buildings) { }

        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first) {
                if (a.second * b.second < 0)
                    return a.second > b.second;
                else if (a.second > 0)
                    return buildings[a.second-1][2] > buildings[b.second-1][2];
                else
                    return buildings[-a.second-1][2] < buildings[-b.second-1][2];
            } else
                return a.first < b.first;
        }
    };

    int n;
    vector<pair<int, int>> heap;
    vector<int> id2heap;

    void shift_up(int cur) {
        if (cur == 0) return;
        int p = (cur-1)/2;
        if (heap[cur].first > heap[p].first) {
            swap(heap[cur], heap[p]);
            swap(id2heap[heap[cur].second], id2heap[heap[p].second]);
            shift_up(p);
        }
    }

    void shift_down(int cur) {
        int v = cur;
        if (cur*2+1 < n && heap[cur*2+1].first > heap[v].first)
            v = cur*2+1;
        if (cur*2+2 < n && heap[cur*2+2].first > heap[v].first)
            v = cur*2+2;
        if (v != cur) {
            swap(heap[cur], heap[v]);
            swap(id2heap[heap[cur].second], id2heap[heap[v].second]);
            shift_down(v);
        }
    }

    void heap_insert(int height, int id) {
        heap[n] = make_pair(height, id);
        id2heap[id] = n;
        shift_up(n);
        n++;
    }

    void heap_delete(int id) {
        assert(n > 0);
        int cur = id2heap[id];
        swap(heap[cur], heap[n-1]);
        swap(id2heap[heap[cur].second], id2heap[id]);
        n--;
        shift_down(cur);
    }

    int heap_max() {
        if (n == 0)
            return 0;
        else
            return heap[0].first;
    }

public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        n = 0;
        heap.resize(buildings.size());
        id2heap.resize(buildings.size());

        vector<pair<int, int>> results;
        vector<pair<int, int>> points;

        for (int i = 0; i < buildings.size(); i++) {
            points.push_back(make_pair(buildings[i][0], i+1));
            points.push_back(make_pair(buildings[i][1], -(i+1)));
        }
        Comparator compare(buildings);
        sort(points.begin(), points.end(), compare);

        for (auto& p : points) {
            pair<int, int> res;
            if (p.second > 0) {
                int i = p.second-1;
                heap_insert(buildings[i][2], i);
                res = make_pair(p.first, heap_max());
            } else {
                int i = -p.second-1;
                heap_delete(i);
                res = make_pair(p.first, heap_max());
            }
            if (results.empty() || results.back().second != res.second)
                results.push_back(res);
        }

        return results;
    }
};

int main() {
    Solution sol;
    /* vector<vector<int>> buildings = { {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8} }; */
    /* vector<vector<int>> buildings = { {0, 2, 3}, {2, 5, 3} }; */
    /* vector<vector<int>> buildings = {{2,4,7},{2,4,5},{2,4,6}}; */
    vector<vector<int>> buildings = {{6765,184288,53874},{13769,607194,451649},{43325,568099,982005},{47356,933141,123943},{59810,561434,119381},{75382,594625,738524},{111895,617442,587304},{143767,869128,471633},{195676,285251,107127},{218793,772827,229219},{316837,802148,899966},{329669,790525,416754},{364886,882642,535852},{368825,651379,6209},{382318,992082,300642},{397203,478094,436894},{436174,442141,612149},{502967,704582,918199},{503084,561197,625737},{533311,958802,705998},{565945,674881,149834},{615397,704261,746064},{624917,909316,831007},{788731,924868,633726},{791965,912123,438310}};
    vector<pair<int, int>> results = sol.getSkyline(buildings);
    for (auto& p : results) {
        cout << p.first << ' ' << p.second << endl;
    }
}
