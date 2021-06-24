//https://www.hackerrank.com/contests/sda-homework-9/challenges/bonus-3
#include <bits/stdc++.h>
using namespace std;

struct suffix 
{ 
    int index; 
    int rank[2];
}; 
int cmp(struct suffix a, struct suffix b) 
{ 
    return (a.rank[0] == b.rank[0])? (a.rank[1] < b.rank[1] ?1: 0): (a.rank[0] < b.rank[0] ?1: 0); 
} 

int *buildSuffixArray(char *txt, int n) 
{ 
    struct suffix suffixes[n]; 
    for (int i = 0; i < n; i++) 
    { 
        suffixes[i].index = i; 
        suffixes[i].rank[0] = txt[i] - 'a'; 
        suffixes[i].rank[1] = ((i+1) < n)? (txt[i + 1] - 'a'): -1; 
    } 

    sort(suffixes, suffixes+n, cmp); 
    int ind[n];
    for (int k = 4; k < 2*n; k = k*2) 
    { 
        int rank = 0; 
        int prev_rank = suffixes[0].rank[0]; 
        suffixes[0].rank[0] = rank; 
        ind[suffixes[0].index] = 0; 
        for (int i = 1; i < n; i++) 
        { 
            if (suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i-1].rank[1]) 
            { 
                prev_rank = suffixes[i].rank[0]; 
                suffixes[i].rank[0] = rank; 
            } 
            else
            { 
                prev_rank = suffixes[i].rank[0]; 
                suffixes[i].rank[0] = ++rank; 
            } 
            ind[suffixes[i].index] = i; 
        } 
        for (int i = 0; i < n; i++) 
        { 
            int nextindex = suffixes[i].index + k/2; 
            suffixes[i].rank[1] = (nextindex < n)? suffixes[ind[nextindex]].rank[0]: -1; 
        } 
        sort(suffixes, suffixes+n, cmp); 
    } 
    int *suffixArr = new int[n]; 
    for (int i = 0; i < n; i++)
    {
        suffixArr[i] = suffixes[i].index; 
    }
    return suffixArr; 
} 
void printArr(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; 
    }
    cout << endl; 
} 
int main() 
{ 
    char txt[2000000];
    cin.getline (txt,2000000);
    int n = strlen(txt); 
    int *suffixArr = buildSuffixArray(txt, n);
    printArr(suffixArr, n); 
    return 0; 
} 
