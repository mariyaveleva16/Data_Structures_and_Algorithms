//https://www.hackerrank.com/contests/homework-11/challenges/tunnel-maps
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct Tunnel {
    int to, c, w;
    Tunnel(int to, int w, int c = 0){
        this->to = to;
        this->c = c;
        this->w = w;
    }
};

typedef vector<vector<Tunnel>> Graph;

Graph create(int N, int M) {
    Graph g(N);
    while (M--) {
        int u, v, c, t;
        cin >> u >> v >> c >> t;
        g[u - 1].emplace_back(v - 1, t, c);
    }
    return g;
}

bool cmp(Tunnel &first, Tunnel &second) {
    return first.w > second.w;
}

vector<int> dijkstra(const Graph &g, int start, int maxAllowed) {
    priority_queue<Tunnel, vector<Tunnel>, decltype(&cmp)> path(&cmp);
    vector<int> distance(g.size(), 1000000000);
    vector<bool> isOut(g.size());
    distance[start] = 0;
    path.emplace(start, 0);
    while (!path.empty()) {
        int curr = path.top().to;
        path.pop();
        if (isOut[curr]) continue;
        for (auto[v, c, w]: g[curr])
            if (c <= maxAllowed && distance[v] > distance[curr] + w) {
                distance[v] = distance[curr] + w;
                path.emplace(v, distance[v]);
            }
        isOut[curr] = true;
    }
    return distance;
}

int binarySearch(const Graph &g, int Min, int Max, int T) {
    int bestPath = 1000000000;
    while (Min <= Max) {
        int middle = (Min + Max) / 2;
        int dist = dijkstra(g, 0, middle).back();
        if (dist <= T) {
            bestPath = middle;
            Max = middle - 1;
        } else
            Min = middle + 1;
    }
    if(bestPath != 1000000000) return bestPath;
    else return -1;
}

int main() {
    int N, M, T;
    cin >> N >> M >> T;
    Graph g = create(N, M);
    cout << binarySearch(g, 1, 1000000, T) << endl;
}
