#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
#include <cstring>
#include <cstdint>

using namespace std;

struct ip_sub {
    uint32_t ip;
    int prefix;
    ip_sub() : ip(0), prefix(0) {}
    ip_sub(uint32_t ip, int prefix) : ip(ip), prefix(prefix) {}
};

struct cmp {
    bool operator() (const ip_sub& a, const ip_sub& b) const{
        return a.prefix < b.prefix;
    }
};
struct cmp2 {
    bool operator() (const ip_sub& a, const ip_sub& b) const{
        if (a.ip == b.ip)
            return a.prefix < b.prefix;
        else
            return a.ip < b.ip;
    }
};

void print(const ip_sub& t) {
    int a = t.ip >> 24;
    int b = (t.ip >> 16) & ((1<<8)-1);
    int c = (t.ip >> 8) & ((1<<8)-1);
    int d = t.ip & ((1<<8)-1);
    cout << a << "." << b << "." << c << "." << d << "/" << t.prefix << endl;
    /* bitset<32> bs(t.ip); */
    /* cout << bs << endl; */
}

void work() {
    int N;
    cin >> N;
    vector<ip_sub> ips;
    while (N-- > 0) {
        uint32_t a, b, c, d;
        int p;
        scanf("%u.%u.%u.%u/%d\n", &a, &b, &c, &d, &p);
        ip_sub t;
        t.ip = a << 24 | b << 16 | c << 8 | d;
        t.ip = (t.ip >> (32-p)) << (32-p);
        t.prefix = p;
        ips.push_back(t);
    }
    sort(ips.begin(), ips.end(), cmp());

    vector<set<uint32_t>> data(33);
    for (auto& each : ips) {
        bool flag = true;
        for (int i = 32; i >= 32-each.prefix; i--)
            if (data[i].count(each.ip >> i)) {
                flag = false;
                break;
            }
        if (flag)
            data[32-each.prefix].insert(each.ip >> (32-each.prefix));
    }

    for (int i = 0; i <= 32; i++) {
        for (auto it = data[i].begin(); it != data[i].end(); ) {
            if ((*it & 1) == 0 && data[i].count(*it+1)) {
                uint32_t next = *it >> 1;
                it = data[i].erase(it);
                it = data[i].erase(it);
                data[i+1].insert(next);
            } else
                it++;
        }
    }

    vector<ip_sub> res;
    for (int i = 0; i <= 32; i++)
        for (auto& each : data[i])
            res.push_back(ip_sub(each << i, 32-i));
    sort(res.begin(), res.end(), cmp2());
    for (const ip_sub& each : res) {
        print(each);
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ":" << endl;
        work();
    }
}
