//https://www.hackerrank.com/contests/homework-11/challenges/shortest-paths-2
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<climits>

using namespace std;

int main() {
    int N, M;
    const long long MAX = 1e5;
    vector<pair<long long, long long>> graph[MAX];
    cin >> N >> M;
    int x, y;
    long long w;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> w;
        graph[x - 1].push_back(make_pair(y - 1, w));
    }
    long long distance[MAX];
    long long paths[MAX];
    for (int i = 0; i < MAX; i++)
    {
        distance[i] = LLONG_MAX;
        paths[i] = 0;
    }
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> shPaths;
    shPaths.push(make_pair(0, 0));
    distance[0] = 0;
    paths[0] = 1;
    bool visitedN[MAX];
    long long modul = 1e9+7;
    while (!shPaths.empty())
    {
        int curN = shPaths.top().second;
        long long curL = shPaths.top().first;
        shPaths.pop();
        if (!visitedN[curN]) {
            visitedN[curN] = true;
            for (auto v : graph[curN])
            {
                int node = v.first;
                long long weight = v.second;
                if (!visitedN[node] && distance[node] > distance[curN] + weight) {

                    shPaths.push({ curL + weight, node });
                    distance[node] = distance[curN] + weight;
                    paths[node] = paths[curN];
                }
                else if (!visitedN[node] && distance[node] == distance[curN] + weight) {

                    paths[node] = (paths[node] + paths[curN]) % modul;
                }
                paths[node] = paths[node] % modul;
            }
        }

    }

    if (paths[N - 1] == 0) {
        cout << -1<<" "<<0;
    }
    else {
        cout << distance[N - 1] << " " << (paths[N - 1]) % modul;
    }
    return 0;
}
