#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
using namespace std;

typedef pair<int, int> coordinate_t;
int dx[] = { 0, 1, 0,-1};
int dy[] = { 1, 0,-1, 0};

void work() {
    int R, C, S;
    cin >> S >> R >> C;
    std::vector<int> actions_time(S);
    std::vector<char> actions(S);
    for (int i = 0; i < S; i++)
        cin >> actions_time[i] >> actions[i];

    map<coordinate_t, int> snake;
    coordinate_t head = make_pair(1, 1);
    snake[head] = 0;
    int direction = 0;
    std::set<coordinate_t> used;
    int length = 1;

    int i = 0;
    for (int t = 1; t <= 1000000000; t++) {
        // move
        coordinate_t next = make_pair(head.first + dx[direction], head.second + dy[direction]);
        if (next.first > R)
            next.first = 1;
        else if (next.first == 0)
            next.first = R;
        if (next.second > C)
            next.second = 1;
        else if (next.second == 0)
            next.second = C;
        head = next;
        if ((next.first + next.second) & 1 && !used.count(next)) {
            used.insert(next);
            length++;
        }

        pair<map<coordinate_t, int>::iterator, bool> ret = snake.insert(make_pair(next, t));
        if (!ret.second && ret.first->second >= t - length + 1)
            break;
        if (!ret.second)
            ret.first->second = t;

        // turn
        if (i < S && actions_time[i] == t) {
            if (actions[i] == 'R') {
                direction = (direction + 1) % 4;
            } else {
                direction = (direction + 3) % 4;
            }
            i++;
        }

        if (i == S && t > actions_time[S-1] + 2*R && t > actions_time[S-1] + 2*C)
            break;
    }
    cout << length << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        work();
    }
}
