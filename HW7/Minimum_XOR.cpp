//https://www.hackerrank.com/contests/sda-homework-7/challenges/minimum-xor-3
#include <stdio.h> 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <limits.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int min_xor = INT_MAX;  
    vector<int> myvector;
    myvector.push_back(0);
    for (int i = 1; i < n+1; i++)
    {
        int x;
        cin >> x;
        if (count(myvector.begin(), myvector.end(), x)) cout << min_xor << endl;
        else {
            myvector.push_back(x);
            for (int j = 0; j < myvector.size() - 1; j++)
            {
                min_xor = min(min_xor, myvector[j] ^ myvector.back());
            }
            cout << min_xor << endl;
        }
    }
    return 0;
}
