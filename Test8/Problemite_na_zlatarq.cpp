//https://www.hackerrank.com/contests/sda-2020-2021-test8-immwjff/challenges/challenge-1604/problem
#include <bits/stdc++.h>
using namespace std;

void pairSum(int arr[], int n)
{
    bool check=0;
    unordered_set<int> s;
    int sum=arr[0];
    int count=0;
        for (int i = 0; i < n; i++) 
        {
            int temp = sum - arr[i];
 
            if (s.find(temp) != s.end()) 
            {
                check=1; 
                break;
            }
 
            s.insert(arr[i]);
            if(i==n-1 && count<n-1)
            {
                count++;
                sum=arr[count];
                i=0;
            } 
        }
    
    if(check == 0) cout << "false";
    else cout<<"true";
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    int* arr;
    arr = new int[N];
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    pairSum(arr, N);
   // return 0;
}
