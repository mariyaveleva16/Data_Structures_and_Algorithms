//https://www.hackerrank.com/contests/sda-2020-2021-test12-12ws4dw/challenges/challenge-2817
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void addEdge(vector <pair<int, int> > graph[], int u, int v, int wt) 
{ 
    graph[u].push_back(make_pair(v, wt)); 
    graph[v].push_back(make_pair(u, wt)); 
} 

int main() 
{  
    int N, M, K, xi, yi, wi, zi, T, L, path;
    cin >> N >> M;
    vector<pair<int, int> > graph[N];
    vector<int> badNumbers(K);
    vector<int> bitNum (T);
    int** A = new int*[N];
    for (int i = 0; i < N; i++)
        A[i] = new int[N];
 
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            A[i][j] = 0;
    for(int i = 0; i < M; i++)
    {
        cin >> xi >> yi >> wi;
        addEdge(graph, xi, yi, wi);
        A[xi][yi]=wi;
    }
    cin >> K;
    for(int i = 0; i < K; i++)
    {
        cin >> zi;
        badNumbers.push_back(zi);
    }
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        bitNum[i] = 0;
        cin >> L;
        vector<int> requested(L);
        for(int j = 0; j < L; j++)
        {
            cin>>path;
            requested.push_back(path);
        }
        for(int j = 0; j < L-1; j++)
        {
            if(A[requested[j]][requested[j+1]]!=0)
            {
                for(int p=0; p<K; p++)
                {
                    if(badNumbers[p]==A[requested[j]][requested[j+1]]){
                        bitNum[i]=0;
                        break;
                    }
                }
            }
            else
            { 
                bitNum[i]=0;
            }
        }
        cout<<bitNum[i];
    }
    return 0;
}
