//https://www.hackerrank.com/contests/sda-2020-2021-test10-f43j2hj/challenges/challenge-2795
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <unordered_map>
using namespace std;

vector<bool> visitedN;
unordered_map<int, int> umap;
vector<list<pair<int, int>>> Graph;
void solve(int v, int length, int pathCost, int K) {
    if (length == K) {
        ++umap[pathCost];
        return;
    }
    
    visitedN[v] = true;
    for (const auto &p : Graph[v]) {
        int child = p.first;
        int weight = p.second;

        if (!visitedN[child])
            solve(child, length + 1, pathCost + weight, K);
    }
    visitedN[v] = false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int V, E, v1, v2, wi ,K;
    cin >> V >> E;
    Graph.assign(V, list<pair<int, int>>());
    visitedN.assign(V, false);

    while (E--) {
        cin >> v1 >> v2 >> wi;
        v1--, v2--;
        Graph[v1].push_back({v2, wi});
    }

    cin >> K;

    for (int i=0; i < V; ++i)
        solve(i, 0, 0, K);

    int costOfPath = -1, time = 0;

    for (const auto &p : umap) {
        int curCost = p.first;
        int curTime = p.second;

        if (curTime > time || (curTime == time && curCost > costOfPath)) {
            costOfPath = curCost;
            time = curTime;
        }
    }
    cout << costOfPath;
}
