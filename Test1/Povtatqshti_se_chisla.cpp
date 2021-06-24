//https://www.hackerrank.com/contests/sda-2020-2021-test1/challenges/1-257
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, M, a, b;
    cin >> N ;
    vector<int> ai;
    vector<int> bi;
    for(int i = 0; i < N; i++)
    {
        cin >> a;
        ai.push_back(a);
    }
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> b;
        bi.push_back(b);
    }
    sort(ai.begin(), ai.end());
    sort(bi.begin(), bi.end());
    for(int i = 1; i < ai.size() - 2; i++)
    {
        if(ai[i] == ai[i+1] || ai[i] == ai[i-1]) ai.erase(ai.begin()+(i));
    }
    for(int i = 1; i < bi.size() - 2; i++)
    {
        if(bi[i] == bi[i+1] || bi[i] == bi[i-1]) bi.erase(bi.begin()+(i));
    }
    int sum = 0;
    vector<int> newVector(ai.size() + bi.size());
    vector<int>::iterator it, end;
    it = set_intersection(ai.begin(), ai.end(), bi.begin(), bi.end(), newVector.begin());
    for(end = newVector.begin(); end != it; end++)
    {
        sum = sum + *end;
    }
    cout << sum;
    return 0;
}
