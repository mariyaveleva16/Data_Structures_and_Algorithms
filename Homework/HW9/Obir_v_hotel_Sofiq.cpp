//https://www.hackerrank.com/contests/sda-homework-9/challenges/challenge-2739
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

long long a[5000000], b[5000000];
void solve()
{
    long long n;
    int count = 0;
    multiset<long long> s;
    cin >> n;
    for (int i = 0; i < n-1; i++) 
    {
        cin >> b[i];
    }
    for (int i = 0; i < n-1; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n-1; i++) 
    {
        s.insert(b[i]);
        auto iter = s.find(a[i]);
        if (iter == s.end()) 
        {
            count++;
        }
        else 
        {
            s.erase(iter);
        }
    }
    cout << count << "\n";
}
int main() {
    solve();
    return 0;
}
