//https://www.hackerrank.com/contests/sda-homework-12/challenges/challenge-2801
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
const int MAX = 100000;
int parent[MAX];
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int hours = 0; //or 1
    int components = n;
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
 
    }
    int v1, v2;
    bool flag = true;
    if (n == 1)flag = false;
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2;
        v1--;
        v2--;
        if(flag) hours++;
        if (parent[v1] != parent[v2]) {
            int oldParent = parent[v1];
            int newParent = parent[v2];
            for (int i = 0; i < n; i++)
            {
                if (parent[i] == oldParent) {
                    parent[i] = newParent;
                }
            }
            components--;
        }
 
        if (components == 1) {
            flag = false;
        }
    }
    if (components > 1) {
        cout << -1;
    }
    else {
        cout << hours;
    }
    return 0;
}
