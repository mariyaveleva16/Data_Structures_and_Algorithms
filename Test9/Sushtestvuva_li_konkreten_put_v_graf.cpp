//https://www.hackerrank.com/contests/sda-2020-2021-test9-wefnkcsdw/challenges/challenge-2763
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int M, i, j, c, x, Q;
    cin>>M;
    int** arr= new int*[M];
    for(i=0; i<M; i++)
    {
        arr[i]=new int[M];
    }
    for(i=0; i<M; i++)
    {
        for(j=0; j<M; j++)
        {
            arr[i][j]=0;
        }
    }
    for(i=0; i<M; i++)
    {
        cin>>c;
        for(j=0; j<c; j++)
        {
            cin>>x;
            arr[i][x]=1;
            arr[x][i]=1;
        }
    }
    cin>>Q;
    for(i=0; i<Q; i++)
    {
        cin>>c;
        vector<int> vect;
        for(j=0; j<c; j++)
        {
            cin>>x;
            vect.push_back(x);
        }
        bool check=1;
        for(j=0; j<c-1; j++)
        {
            if(arr[vect[j]][vect[j+1]]==0) {check=0; break;}
        }
        cout<<check<<" ";
    }
}
