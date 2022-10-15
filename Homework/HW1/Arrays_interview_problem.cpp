//https://www.hackerrank.com/contests/sda-homework-1/challenges/arrays-interview-problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, x;
    cin>>N;
    vector<int> arr;
    for(int i=0; i<N; i++)
    {
        cin>>x;
        if(x>0){
            arr.push_back(x);
        }
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<N-1; i++)
    {
        if(arr[i]+1!=arr[i+1]){
            cout<<arr[i]+1; 
            break;
        }
    }
    return 0;
}
