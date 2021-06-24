//https://www.hackerrank.com/contests/sda-2020-2021-test11-43ed5rf/challenges/challenge-1761
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

vector<set<int>> Nodes;
queue<int> myQueue;
vector<int> markedNodes;
int main() {
    ios_base::sync_with_stdio(false);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int V, E, v1, v2;
    int maxDeleted = 0;
    cin >> V >> E;
    Nodes.assign(V + 1, set<int>());
    markedNodes.assign(V + 1, 0);
    for (int i = 0; i < E; i++) 
    {
        cin >> v1 >> v2;
        Nodes[v1].insert(v2);
        Nodes[v2].insert(v1);
    }
    for (int i = 1; i <= V; i++)
    {
        if (Nodes[i].size() < 2) myQueue.push(i);
    }
    while (!myQueue.empty()) 
    {
        v1 = myQueue.front();
        myQueue.pop();
        if (Nodes[v1].size() < 1) continue;
        v2 = *Nodes[v1].begin();
        Nodes[v2].erase(v1);
        if (Nodes[v2].size() < 2) myQueue.push(v2);
        if (markedNodes[v1]) maxDeleted++;
        else markedNodes[v2] ^= 1;
    }

    return cout << maxDeleted, 0;
}
