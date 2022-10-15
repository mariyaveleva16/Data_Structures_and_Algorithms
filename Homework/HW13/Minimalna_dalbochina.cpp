//https://www.hackerrank.com/contests/sda-homework-13/challenges/challenge-2806
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <climits>
using namespace std;
#define maxN 100001

vector<int> graph[maxN];
int height[maxN];
int dist[maxN];
void addEdge(int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void DFSFirst(int current, int edge)
{
    for (auto p : graph[current]) 
    {
        if (p != edge) 
        {
            DFSFirst(p, current);
            height[current] = max(height[current], height[p]);
        }
    }
    height[current] += 1;
}
void DFSSecond(int current, int edge)
{
    int max1 = 0;
    int max2 = 0;
    for (auto p : graph[current]) 
    {
        if (p != edge) 
        {
            if (height[p] >= max1) 
            {
                max2 = max1;
                max1 = height[p];
            }
            else if (height[p] > max2) 
            {
                max2 = height[p];
            }
        }
    }
    for (auto p : graph[current]) 
    {
        if (p != edge) 
        {
            if (max1 == height[p])
                dist[p] = 1 + max(1 + max2, dist[current]);
            else
                dist[p] = 1 + max(1 + max1, dist[current]);
            DFSSecond(p, current);
        }
    }
}
int main()
{
    int N , a , b;
    cin >> N;
    vector<int> distances;
    for(int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        a++; b++;
        addEdge(a, b);
    }
    DFSFirst(1, 0);
    DFSSecond(1, 0);
    for (int i = 1; i <= N; i++)
    {
        distances.push_back(max(dist[i], height[i]) - 1);
    }
    int minElement = *min_element(distances.begin(), distances.end());
    for(int i = 0; i < N; i++)
    {
        if(distances[i] == minElement) cout << i << " ";
    }
    return 0;
}
