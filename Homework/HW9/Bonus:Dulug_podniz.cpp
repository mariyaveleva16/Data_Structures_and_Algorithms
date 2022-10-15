//https://www.hackerrank.com/contests/sda-homework-9/challenges/longest-match
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int FindMaxLength(char A[], char B[], int n, int m)
{
    int** dp= new int*[n + 1];
    for (int i = 0; i < n+1; i++)
        dp[i] = new int[m+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = n - 1; i >= 0; i--) 
    {
        for (int j = m - 1; j >= 0; j--) 
        {
            if (A[i] == B[j]) dp[i][j] = dp[i + 1][j + 1] + 1;
        }
    }
    int maxm = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            maxm = max(maxm, dp[i][j]);
        }
    }
    return maxm;
}
 

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    char txt[100000];
    cin.getline (txt,100000);
    int n = strlen(txt); 
    char txt2[100000];
    cin.getline (txt2,100000);
    int m = strlen(txt2); 
    if(0==m|| 0==n) cout<<0;
    else cout << (FindMaxLength(txt, txt2, n, m));
    return 0;
}
