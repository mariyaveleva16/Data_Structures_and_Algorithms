//https://www.hackerrank.com/contests/sda-2020-2021-test7-8jfn4/challenges/challenge-2736
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
int get(int arr[],int arr2[], int x, int N)
{
    int count = 0; 
    int l, r; 
    for (int i = 0; i < N; i++)  
    { 
        l = arr[i]; 
        r = arr2[i];  
        if (x >= l && x <= r) 
        count++; 
    } 
    return count; 
}
void solve()
{
    int N,Q;
    cin>>N>>Q;
    int* start;
    int* end;
    start= new int[N];
    end= new int[N];
    int* arr;
    arr= new int[Q];
    for(int i=0; i<N; i++)
    {
        cin>>start[i]>>end[i];
        
    }
    for(int i=0; i<Q; i++)
    {
        int x;
        cin>>x;
        arr[i]=x;
        cout<<get(start,end, x, N)<<" ";
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    solve();
    return 0;
}
