//https://www.hackerrank.com/contests/sda-homework-9/challenges/0-1-1
#include <bits/stdc++.h> 
using namespace std;

int longestSubarr(int arr[], int N) 
{
    unordered_map<int, int> mymap; 
    int sum = 0, maxLen = 0;
    for (int i = 0; i < N; i++) 
    {
        if(arr[i] == 0) sum = sum - 1;
        else sum = sum + 1;
        if (sum == 0) maxLen = i + 1; 
        else
        { 
            if (mymap.find(sum) == mymap.end()) mymap[sum] = i;  
        }
        if (mymap.find(sum) != mymap.end()) 
        { 
            if (maxLen < (i - mymap[sum])) maxLen = i - mymap[sum]; 
        } 
    }
    return maxLen;
}
void solve()
{
    int N;
    int* arr;
    cin >> N;
    arr = new int[N];
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cout << longestSubarr(arr, N);
}
int main() 
{ 
    solve();
    return 0; 
} 

