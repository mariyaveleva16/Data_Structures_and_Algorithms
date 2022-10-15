//https://www.hackerrank.com/contests/sda-2020-2021-test9-wefnkcsdw/challenges/challenge-2762
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
class Graph {
    int N;
    int cnt;
    list<int>* adj;
    void DFSUtil(int v, bool visited[]);

public:
    Graph(int N);
    ~Graph();
    void addEdge(int v, int w);
    void connected();
};
void Graph::connected()
{
    int Number = 0;
    bool* visited = new bool[N];
    for (int v = 0; v < N; v++)
        visited[v] = false;

    for (int v = 0; v < N; v++) {
        if (visited[v] == false) {
            cnt = 0;
            DFSUtil(v, visited);
            if (cnt > 0) Number++;
        }
    }
    delete[] visited;
    cout << Number;
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;   
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i]){DFSUtil(*i, visited);cnt++;}
            
}

Graph::Graph(int N)
{
    this->N = N;
    adj = new list<int>[N];
}

Graph::~Graph() { delete[] adj; }
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
int main()
{
    int N, M;
    cin >> N >> M;
    Graph graph(N);
    for (int i = 0; i < M; i++)
    {
        int xi, yi;
        cin >> xi >> yi;
        graph.addEdge(xi, yi);
    }
    graph.connected();

    return 0;
}
