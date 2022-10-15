//https://www.hackerrank.com/contests/sda-homework-12/challenges/roads-5
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> paths;

int findPath(int a) 
{
    if (paths[a] == a) return a;
    else return paths[a] = findPath(paths[a]);
}

void calls(int a, int b) 
{
    int x = findPath(a), y = findPath(b);
    if (x == y) return;
    else paths[y] = x;
}

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N, M, Q;
    cin >> N >> M;
    vector<pair<int, int>> cities;
    paths.resize(N + 1);
    int a, b;
    for (int i = 0; i < M; i++) 
    {
        cin >> a >> b;
        cities.push_back(make_pair(a, b));
    }
    for (int i = 0; i < N; i++)
    {
        paths[i] = i;
    }
    for (int i = 0; i < M; i++)
    {
        calls(cities[i].first, cities[i].second);
    }
    
    int callType, a1, b1;
    cin >> Q;
    for (int i = 0; i < Q; i++) 
    {
        cin >> callType >> a1 >> b1;
        if (callType == 1) cout << (findPath(a1) == findPath(b1));
        else calls(a1, b1);
    }
}
