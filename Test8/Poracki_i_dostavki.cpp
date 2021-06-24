//https://www.hackerrank.com/contests/sda-2020-2021-test8-immwjff/challenges/1-140
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map> 
using namespace std;

void count(int arr[], int n) 
{
    int bags=0;
    int items=0;
    unordered_map<int, int> mp; 
    for (int i = 0; i < n; i++){
        mp[arr[i]]++; 
        if(mp[arr[i]]==10) mp[arr[i]]=0;
    } 
        
    for (auto x : mp){
        if (x.second!=0) bags++;
        items=items+x.second;
    }
    cout<<bags<<" "<<items;
} 
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin>>N;
    int* arr;
    arr= new int[N];
    for(int i=0; i<N; i++)
    {
        cin>>arr[i];
    }
    count(arr, N);
    return 0;
}
