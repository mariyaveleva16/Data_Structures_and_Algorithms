//https://www.hackerrank.com/contests/sda-2020-2021-test7-8jfn4/challenges/challenge-2737
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct compareMoney{
    bool operator()(int& a, int& b)
    {
        return a < b;
    }
};
void solve()
{
    int N;
    cin>>N;
    priority_queue<int, vector<int>, compareMoney> people;
    for(int i=0; i<N; i++)
    {
        int x;
        cin>>x;
        if (-1==x && !people.empty() ){
            cout<< people.top()<<" "; 
            people.pop();
        }
        if(-1!=x) people.push(x);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    solve();
    return 0;
}
