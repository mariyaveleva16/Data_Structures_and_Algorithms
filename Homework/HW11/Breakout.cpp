//https://www.hackerrank.com/contests/homework-11/challenges/breakout
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;
const int MAX = 1000;
int arr[MAX][MAX];
bool used[MAX][MAX];
int dist[MAX][MAX];
 
void solve(int N, int M) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i = 0; i < N; i++) {
        used[i][0] = true;
        used[i][M - 1] = true;
        dist[i][0] = arr[i][0];
        dist[i][M - 1] = arr[i][M - 1];
        pq.push({ dist[i][0], {i,0} });
        pq.push({ dist[i][M - 1], {i,M - 1} });
 
    }
    for (int i = 0; i < M; i++) {
        if (!used[0][i]) {
            used[0][i] = true;
            dist[0][i] = arr[0][i];
            pq.push({ dist[0][i], {0,i} });
 
        }
        if (!used[N - 1][i]) {
            used[N - 1][i] = true;
            dist[N - 1][i] = arr[N - 1][i];
            pq.push({ dist[N - 1][i], {N - 1,i} });
        }
    }
    while (!pq.empty()) {
        auto temp = pq.top();
        pq.pop();
        int i, j;
        i = temp.second.first;
        j = temp.second.second;
        if (i > 0 && !used[i - 1][j]) {
            used[i - 1][j] = true;
            dist[i - 1][j] = dist[i][j] + arr[i - 1][j];
            pq.push({ dist[i - 1][j],{i - 1,j} });
        }
        if (i < N - 1 && !used[i + 1][j]) {
            used[i + 1][j] = true;
            dist[i + 1][j] = dist[i][j] + arr[i + 1][j];
            pq.push({ dist[i + 1][j],{i + 1,j} });
        }
        if (j > 0 && !used[i][j - 1]) {
            used[i][j - 1] = true;
            dist[i][j - 1] = dist[i][j] + arr[i][j - 1];
            pq.push({ dist[i][j - 1],{i,j - 1} });
        }
        if (j < M - 1 && !used[i][j + 1]) {
            used[i][j + 1] = true;
            dist[i][j + 1] = dist[i][j] + arr[i][j + 1];
            pq.push({ dist[i][j + 1],{i,j + 1} });
        }
    }
 
    int max = INT_MIN;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (dist[i][j] > max && arr[i][j] == 0) {
                max = dist[i][j];
                count = 1;
            }
            else if (dist[i][j] == max && arr[i][j] == 0) {
                count++;
            }
        }
    }
    cout << count;
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
 
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (size_t j = 0; j < temp.size(); j++)
        {
            if (temp[j] == '.') {
                arr[i][j] = 0;
            }
            else if (temp[j] == '#') {
                arr[i][j] = 1;
            }
        }
    }
 
    solve(N, M);
    return 0;
}
