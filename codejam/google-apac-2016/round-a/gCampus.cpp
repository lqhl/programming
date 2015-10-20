/*
 * Contest: Google APAC 2016 University Graduates Test - Round A
 * Problem: gCampus
 * Author: Qin Liu
 *
 * Tag: graph
 */
#include <iostream>
#include <vector>
#include <string>
#include <list>

#include <limits> // for numeric_limits

#include <set>
#include <utility> // for pair
#include <algorithm>
#include <iterator>

using namespace std;

typedef int vertex_t;
typedef int weight_t;

const weight_t max_weight = std::numeric_limits<int>::max();

struct neighbor {
    vertex_t target;
    weight_t weight;
    vertex_t order;
    neighbor(vertex_t arg_target, weight_t arg_weight, vertex_t arg_order)
        : target(arg_target), weight(arg_weight), order(arg_order) { }
};

typedef std::vector<std::vector<neighbor> > adjacency_list_t;


void DijkstraComputePaths(vertex_t source,
        const adjacency_list_t &adjacency_list,
        std::vector<weight_t> &min_distance,
        std::vector<std::vector<vertex_t> > &previous) {
    int n = adjacency_list.size();
    min_distance.clear();
    min_distance.resize(n, max_weight);
    min_distance[source] = 0;
    previous.clear();
    previous.resize(n);
    std::set<std::pair<weight_t, vertex_t> > vertex_queue;
    vertex_queue.insert(std::make_pair(min_distance[source], source));

    while (!vertex_queue.empty()) {
        weight_t dist = vertex_queue.begin()->first;
        vertex_t u = vertex_queue.begin()->second;
        vertex_queue.erase(vertex_queue.begin());

        // Visit each edge exiting u
        const std::vector<neighbor> &neighbors = adjacency_list[u];
        for (std::vector<neighbor>::const_iterator neighbor_iter = neighbors.begin();
                neighbor_iter != neighbors.end();
                neighbor_iter++) {
            vertex_t v = neighbor_iter->target;
            weight_t weight = neighbor_iter->weight;
            weight_t distance_through_u = dist + weight;
            if (distance_through_u < min_distance[v]) {
                vertex_queue.erase(std::make_pair(min_distance[v], v));

                min_distance[v] = distance_through_u;
                previous[v].clear();
                previous[v].push_back(neighbor_iter->order);
                vertex_queue.insert(std::make_pair(min_distance[v], v));
            } else if (distance_through_u == min_distance[v]) {
                previous[v].push_back(neighbor_iter->order);
            }

        }
    }
}


int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, M;
        cin >> N >> M;
        adjacency_list_t adjacency_list(N);
        for (int e = 0; e < M; e++) {
            int u, v, w;
            cin >> u >> v >> w;
            adjacency_list[u].push_back(neighbor(v, w, e));
            adjacency_list[v].push_back(neighbor(u, w, e));
        }

        std::vector<bool> used(M, false);
        for (int start = 0; start < N; start++) {
            std::vector<weight_t> min_distance;
            std::vector<std::vector<vertex_t> > previous;
            DijkstraComputePaths(start, adjacency_list, min_distance, previous);
            for (int i = 0; i < N; i++)
                for (size_t j = 0; j < previous[i].size(); j++)
                    used[previous[i][j]] = true;
        }
        cout << "Case #" << t << ":" << endl;
        for (int e = 0; e < M; e++)
            if (!used[e])
                cout << e << endl;
    }

    return 0;
}
