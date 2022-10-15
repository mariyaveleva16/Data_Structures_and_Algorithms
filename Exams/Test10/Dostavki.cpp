//https://www.hackerrank.com/contests/sda-2020-2021-test10-f43j2hj/challenges/challenge-2794
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Graph {
    vector<vector<pair<int, int>>> Nodes;
    vector<bool> visitedN;
    vector<int> paths;

    int v;

    void clearVisited() {
        visitedN.assign(v + 1, 0);
    }

public:
    Graph(int v) : v(v) {
        Nodes.assign(v + 1, vector<pair<int, int>>());
        paths.assign(v + 1, INT_MAX);
    }

    void insert(pair<int, int> v1, pair<int, int> v2) {
        Nodes[v1.second].push_back(v2);
        Nodes[v2.second].push_back(v1);
    }

    void djiikstra(int s) {
        clearVisited();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> shortPth;
        shortPth.push(make_pair(0, s));
        paths[s] = 0;

        while (!shortPth.empty()) {
            int v = shortPth.top().second;
            shortPth.pop();
            if (visitedN[v]) continue;
            visitedN[v] = true;
            for (const auto &child : Nodes[v]) {
                if (visitedN[child.second])
                    continue;
                if (paths[v] + child.first < paths[child.second]) {
                    paths[child.second] = paths[v] + child.first;
                    shortPth.push(make_pair(paths[child.second], child.second));
                }
            }
        }

        for (int i = 1; i <= v; ++i) {
            if (i != s) {
                if (paths[i] == INT_MAX)
                    cout << -1 << " ";
                else
                    cout << paths[i] << " ";
            }
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N, M, x, y, w, s;
    cin >> N >> M;
    Graph G(N);
    while (M--) {
        cin >> x >> y >> w;
        G.insert({w, x}, {w, y});
    }
    cin >> s;
    G.djiikstra(s);
    return 0;
}
