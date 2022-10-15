//https://www.hackerrank.com/contests/sda-homework-5/challenges/challenge-2695
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N,d;
    cin>>N>>d;
    if(N>0 && d>0){
    long long* arr;
    arr=new long long[N];
    for(int i=0; i<N; i++)
    {
        cin>>arr[i];
    }
    long long sum=0;
    deque<int> mydeque(d);
    for(int i=0; i<d; i++)
    {
        while((mydeque.empty()==false) && arr[i]<=arr[mydeque.back()]) mydeque.pop_back();
        mydeque.push_back(i);
    }
    sum=arr[mydeque.front()];
   // cout << arr[mydeque.front()] << " ";
    for(int i=d; i<N; i++)
    {
        
        while((mydeque.empty()==false) && mydeque.front()<= i-d) mydeque.pop_front();
        while((mydeque.empty()==false) && arr[i]<=arr[mydeque.back()]) mydeque.pop_back();
        mydeque.push_back(i);
        sum=sum+arr[mydeque.front()];
        //cout << arr[mydeque.front()] << " ";
    }
    cout<<sum;}
    return 0;
}
