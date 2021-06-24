//https://www.hackerrank.com/contests/sda-homework-10/challenges/challenge-2752
#include<iostream>
#include<vector>
using namespace std;
vector<int> graph[26]; //1000
bool visited[26];
bool needed[26];
vector<int> result;
 
void addEdges(vector<string>& str) {
    for (int i = 0; i < str.size()-1; i++)
    {
        for (int j = 0; j < str[i].size() && str[i + 1].size(); j++)
        {
            needed[str[i][j] - 'a'] = true;
            needed[str[i+1][j] - 'a'] = true;
            if (str[i][j] != str[i + 1][j]) {
                graph[str[i][j] - 'a'].push_back(str[i + 1][j] - 'a');
                break;
            }
        }
    }
}
void dfs(int start) {
    visited[start] = true;
    for (int t:graph[start])
    {
        if (!visited[t]) {
            dfs(t);
        }
    }
    result.push_back(start);
}
 
void topologicalSort() {
    for (int i = 0; i < 26; i++)
    {
        if (!visited[i] && needed[i]) {
            dfs(i);
        }
    }
}
 
void printTopological() {
    topologicalSort();
    for (int i = result.size()-1; i >=0 ; i--)
    {
        cout << (char)(result[i]+'a') << " ";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N;
    cin >> N;
    fill(visited, visited + N, false);
    fill(needed, needed + N, false);
    vector<string> str(N);
    string temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        str[i] = temp;
    }
    addEdges(str);
    printTopological();
 
    return 0;
}
