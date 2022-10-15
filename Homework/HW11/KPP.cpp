//https://www.hackerrank.com/contests/homework-11/challenges/challenge-2774
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<climits>
#include<algorithm>
using namespace std;
const int MAX = 10000;
vector<pair<int, int>> graph[MAX];
bool visited[MAX];
map<pair<int, int>, int>myMap;
//distance, count
pair<int, int> dist[MAX];
int distance[MAX];
void topologicalSortUtil(int v, stack<int>& Stack)
{
    visited[v] = true;
    for (auto i = graph[v].begin(); i != graph[v].end(); ++i) {
        if (!visited[i->first])
            topologicalSortUtil(i->first, Stack);
    }
    Stack.push(v);
}
 
void findLongestPaths(int s, int n, int end)
{
 
    stack<int> Stack;
 
    for (int i = 0; i < MAX; i++) {//n or MAX
        if (visited[i] == false) {
            topologicalSortUtil(i, Stack);
        }
    }
 
    for (int i = 0; i < MAX; i++) {//n or MAX
        dist[i].first = INT_MIN;
        dist[i].second = 0;
 
    }
    dist[s].first = 0;
    dist[s].second = 1;
 
 
    while (Stack.empty() == false) {
        int u = Stack.top();
        Stack.pop();
 
        if (dist[u].first != INT_MIN) {
            for (auto i = graph[u].begin(); i != graph[u].end(); ++i) {
                if (dist[i->first].first < dist[u].first + i->second) {
                    dist[i->first].first = dist[u].first + i->second;
                    dist[i->first].second = dist[u].second;
                }
                else if (dist[i->first].first == dist[u].first + i->second) {
                    dist[i->first].second += dist[u].second;
                }
            }
        }
 
    }
 
 
        cout << dist[end].first << " " << dist[end].second;
 
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
    int v1, v2, w;
 
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2 >> w;
        graph[v1].push_back({ v2,w });
    }
    int A, B;
    cin >> A >> B;
    findLongestPaths(A, n, B); 
    return 0;
}
