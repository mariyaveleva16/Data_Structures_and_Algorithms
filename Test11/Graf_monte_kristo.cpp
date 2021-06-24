//https://www.hackerrank.com/contests/sda-2020-2021-test11-43ed5rf/challenges/challenge-2805
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;


vector<list<int>> Nodes;
vector<bool> visitedEdges;
vector<int> topologicalSort;
vector<int> indexes;

void DFS(int v) {
    visitedEdges[v] = true;
    for (const auto &p:Nodes[v])
        if (!visitedEdges[p])
            DFS(p);
    topologicalSort.push_back(v);
    indexes[v] = topologicalSort.size() - 1;
}

int main() {
    int N, V, E, xi, yi, wi;
    cin >> N;

    while (N--) {
        cin >> V >> E;

        Nodes.assign(V, list<int>());
        visitedEdges.assign(V, 0);

        topologicalSort.clear();
        indexes.assign(V, 0);

        while (E--) 
        {
            cin >> xi >> yi >> wi;
            Nodes[xi - 1].push_back(yi - 1);
        }
        for (int i = 0; i < V; ++i)
        {
            if (!visitedEdges[i]) DFS(i);
        }    
        int back_edges(0);
        for (int i = 0; i < V; ++i)
        {
            for (const auto &child:Nodes[i])
            {
                if (indexes[i] < indexes[child]) back_edges++;
            }
        }

        back_edges ? cout << 1 : cout << 0;
    }
    return 0;
}
