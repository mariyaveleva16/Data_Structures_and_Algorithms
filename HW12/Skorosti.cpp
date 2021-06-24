//https://www.hackerrank.com/contests/sda-homework-12/challenges/challenge-2799
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int MAX = 10000;
int N, M;
vector<int> parent;
vector<int> depth;
 
int findSet(int p) 
{
    if (p == parent[p])return p;
    return parent[p] = findSet(parent[p]);
}
 
void unionSets(int v1, int v2) 
{
    v1 = findSet(v1);
    v2 = findSet(v2);
    if (v1 != v2) {
        if (depth[v1] < depth[v2]) swap(v1, v2);
        parent[v2] = v1;
        if (depth[v2] == depth[v2])depth[v1]++;
    }
}
struct Edge 
{
    int v1;
    int v2;
    int w;
    Edge(int v1, int v2, int w)
    {
        this->v1 = v1;
        this->v2 = v2;
        this->w = w;
    }
    bool operator<(const Edge& other)const 
    {
        return this->w < other.w;
    }
};
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    vector<Edge>edges;
    cin >> N >> M;
    int Fi, Ti, Si;
    int min = 0;
    int max = INT_MAX;
    for (int i = 0; i < M; i++)
    {
        cin >> Fi >> Ti >> Si;
        Fi--; Ti--;
        edges.push_back({Fi,Ti,Si});
    }
    vector<Edge> speed;
    parent.resize(N);
    depth.resize(N);
    for (int i = 0; i < N; i++) 
    {
        parent[i] = i;
        depth[i] = 0;
    }
    sort(edges.begin(), edges.end());
    int nodes = N;
    for (size_t j = 0; j < edges.size(); j++)
    {
        for (size_t i = j; i < edges.size(); i++) 
        {
            if (findSet(edges[i].v1) != findSet(edges[i].v2)) 
            {
                speed.push_back(edges[i]);
                unionSets(edges[i].v1, edges[i].v2);
                nodes--;
            }
            if (nodes == 1) 
            {
                break;
            }
        }
        if(nodes == 1) 
        {
            int curMin = speed.begin()->w;
            vector<Edge>::iterator iter = speed.end();
            iter--;
            int curMax = iter->w;
            int cur = curMax - curMin;
            int global = max - min;
            if (cur < global) 
            {
                min = curMin;
                max = curMax;
            }
            nodes = N;
            speed.clear();
            for (int i = 0; i < N; i++) 
            {
                parent[i] = i;
                depth[i] = 0;
            }
        }        
    }
    cout << min << " " << max;
    return 0;
}
