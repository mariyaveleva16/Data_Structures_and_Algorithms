//https://www.hackerrank.com/contests/sda-homework-10/challenges/-1-12/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

enum Color { WHITE, GRAY, BLACK };
class Graph
{
    int V;
    list<int>* adj; 
    bool DFSUtil(int v, int color[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isCyclic();
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
}
bool Graph::DFSUtil(int u, int color[])
{
    color[u] = GRAY;
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;
        if (color[v] == GRAY)
        {
            return true;
        }
        if (color[v] == WHITE && DFSUtil(v, color))
        {
            return true;
        }
    }
    color[u] = BLACK;
    return false;
}
bool Graph::isCyclic()
{
    int* color = new int[V];
    for (int i = 0; i < V; i++)
    {
        color[i] = WHITE;
    }
    for (int i = 0; i < V; i++)
    {
        if (color[i] == WHITE)
            if (DFSUtil(i, color) == true)
                return true;
    }
    return false;
}
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int V, E;
        cin >> V >> E;
        Graph gr(V);
        vector<pair<int, int>> vect;
        for (int j = 0; j < E; j++)
        {
            int xi, yi, wi;
            cin >> xi >> yi >> wi;
            xi--; yi--;
            vect.push_back(make_pair(xi, yi));
        }
        sort(vect.begin(), vect.end());
        for (int j = 0; j < E; j++)
        {
            gr.addEdge(vect[j].first, vect[j].second);
        }
        if (gr.isCyclic())
            cout << "true ";
        else
            cout << "false ";
    }
    return 0;
}

