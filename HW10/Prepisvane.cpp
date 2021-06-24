//https://www.hackerrank.com/contests/sda-homework-10/challenges/challenge-2748
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<iterator>
using namespace std;
vector<pair<int,int>> graph[10000];
bool visited[10000];
 
 
void findShortestDistance(int start,int* distance,int N) {
    distance[start] = 0;
    visited[start] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto i :graph[start])
    {
        distance[i.first] = i.second;
        pq.push({ i.second, i.first });
    }
 
    while (!pq.empty())
    {    
        pair<int, int> curEl = pq.top();
        pq.pop();
        int curNode=curEl.second;
 
        if (!visited[curNode]) {
            visited[curNode] = true;
            for (auto it : graph[curNode])
            {
                int v = it.first;
                int weight = it.second;
                if (!visited[v] && distance[v] > distance[curNode] + weight) {
                    distance[v] = distance[curNode] + weight;
                    pq.push({ distance[v],v });
                }
            }
        }
 
    }
    if (distance[N - 1] == INT_MAX) {
        cout << -1;
    }
    else {
        cout << distance[N - 1];
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    int distance[10000];
 
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < 10000; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    int v1, v2;
    for (int i = 0; i < M; i++)
    {
        cin >> v1 >> v2;
        graph[v1].push_back({ v2,0 });
        graph[v2].push_back({ v1,0 });
    }
    for (int i = 0; i < K; i++)
    {
        cin >> v1 >> v2;
        graph[v1].push_back({ v2,1});
        graph[v2].push_back({ v1,1});
    }
 
    findShortestDistance(0,distance,N);
    return 0;
}
