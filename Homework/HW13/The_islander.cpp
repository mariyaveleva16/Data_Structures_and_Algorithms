//https://www.hackerrank.com/contests/sda-homework-13/challenges/islander
#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int N;
    list<int> *edges;
public:
    Graph(int N): N(N)
    {
        edges = new list<int>[N];
    }
    ~Graph()
    {
        delete [] edges;
    }
    void addEdge(int u, int v);
    void DFS(int n, bool visitedEdges[]);
    bool isGraphConnected();
    int isGraphEulerian();
};
void Graph::addEdge(int u, int v)
{
        edges[u].push_back(v);
        edges[v].push_back(u);
}
void  Graph::DFS(int n, bool visitedEdges[])
{
    visitedEdges[n] = true;
    list<int>::iterator i;
    for(i = edges[n].begin(); i != edges[n].end(); i++)
    {
        if(!visitedEdges[*i])
        {
            DFS(*i, visitedEdges);
        }
    }
}
bool Graph::isGraphConnected()
{
    bool visited[N];
    int i;
    for(i = 0; i < N; i++)
    {
        visited[i] = false;
    }
    for(i = 0; i < N; i++)
    {
        if(edges[i].size() != 0) break;
    }
    if(i == N) return true;
    DFS(i, visited);
    for(i = 0; i < N; i++)
    {
        if(visited[i] == false && edges[i].size() > 0) return false;
    }
    return true;
}
int Graph::isGraphEulerian()
{
    if(isGraphConnected() == false) return 0;
    int odd = 0;
    for(int i = 0; i < N; i++)
    {
        if(edges[i].size() & 1) odd++;
    }
    if(odd > 2) return 0;
    return (odd)? 1 : 2;
}
void test(Graph &g) 
{ 
    int res = g.isGraphEulerian(); 
    if (res == 0) 
        cout << "none\n"; 
    else if (res == 1) 
        cout << "epath\n"; 
    else
        cout << "ecycle\n"; 
} 
int main() 
{
    int queries, N, M, a, b;
    cin >> queries;
    for(int i = 0; i < queries; i++)
    {
        cin >> N >> M;
        Graph myGraph(N);
        for(int j = 0; j < M; j++)
        {
            cin >> a >> b;
            myGraph.addEdge(a, b);
        }
        test(myGraph);
    }
    return 0;
}
