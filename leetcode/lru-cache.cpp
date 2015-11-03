#include "util.hpp"

class LRUCache{
private:
    int c;
    unordered_map<int, int> cache;
    unordered_map<int, int> count;
    deque<int> q;
public:
    LRUCache(int capacity) : c(capacity) { }

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end())
            return -1;
        else {
            q.push_back(key);
            count[key]++;
            return it->second;
        }
    }

    void set(int key, int value) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            if (cache.size() == c) {
                int eject;
                do {
                    eject = q.front();
                    q.pop_front();
                    count[eject]--;
                } while (count[eject] > 0);
                cache.erase(eject);
            }
            q.push_back(key);
            count[key]++;
            cache[key] = value;
        } else {
            q.push_back(key);
            count[key]++;
            it->second = value;
        }
    }
};
