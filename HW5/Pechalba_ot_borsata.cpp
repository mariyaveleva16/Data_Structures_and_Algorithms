//https://www.hackerrank.com/contests/sda-homework-5/challenges/a-225
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
void borsa()
{
    deque<int> mydeque;
    int N;
    long long k, maxsum=0;
    cin>>N>>k;
    int days = 0, mindays = 0;
    for(int i=0; i<N; i++)
    {
        int x;
        cin>>x;
        mydeque.push_back(x);
        maxsum=maxsum+x;
    }
    
    if(N>=1&&k>=1&&maxsum>=k){ 
        if(maxsum==k) cout<<N;
        else{
            long long oldsize=mydeque.size()+1;
            while(oldsize>mydeque.size())
            {
                oldsize=mydeque.size();
        //cout<<"oldsize "<<oldsize<<endl;
                if(mydeque.front()>=k|| mydeque.back()>=k) {mindays=1; break;}
                if(maxsum- mydeque.front()>=k) {maxsum=maxsum-mydeque.front(); mydeque.pop_front(); }
                if(maxsum- mydeque.back()>=k) {maxsum=maxsum-mydeque.back(); mydeque.pop_back();}
                days=mydeque.size();
        //cout<<"newsize "<<mydeque.size()<<endl;
                if(days<mindays||mindays==0) mindays=days;
            }
        cout<<mindays;
        }
    }
    else cout<<-1<<endl;
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    borsa();
    return 0;
}
