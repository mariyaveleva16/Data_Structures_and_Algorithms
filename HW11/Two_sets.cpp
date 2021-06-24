//https://www.hackerrank.com/contests/homework-11/challenges/discos
#include <cstdio>
#include <vector>
#include <list>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

class Graph {
    vector<list<pair<int, int>>> grList;
    vector<bool> visited;

    int v;

    void clearVisited() {
        visited.assign(v + 1, 0);
    }

public:
    vector<int> paths;

    Graph(int v) : v(v) {
        grList.assign(v + 1, list<pair<int, int>>());
        paths.assign(v + 1, INT_MAX);
    }

    void insert(pair<int, int> x, pair<int, int> y) {
        grList[x.second].push_back(y);
        grList[y.second].push_back(x);
    }

    void djiikstra(int start) {
        clearVisited();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> shortPt;
        shortPt.push({0, start});
        paths[start] = 0;

        while (!shortPt.empty()) {
            //int dist = pq.top().first;
            int v = shortPt.top().second;
            shortPt.pop();
            if (visited[v])
                continue;
            visited[v] = true;
            for (const auto &child : grList[v]) {
                if (visited[child.second])
                    continue;
                if (paths[v] + child.first < paths[child.second]) {
                    paths[child.second] = paths[v] + child.first;
                    shortPt.push({paths[child.second], child.second});
                }
            }
        }
    }
};

int main() {
    int N, M, x, y, w, K, t, Q, s;
    cin >> N >> M;
    Graph graph(N);

    while (M--) {
        cin >> x >> y >> w;
        graph.insert({w, x}, {w, y});
    }

    cin >> K;

    while (K--) {
        cin>>t;
        graph.insert({0, t}, {0, N});
    }

    cin >> Q;

    graph.djiikstra(N);

    while(Q--) {
        cin >> s;
        cout << graph.paths[s] << endl;
    } return 0;
}
