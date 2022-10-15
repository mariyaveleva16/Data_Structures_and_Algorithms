//https://www.hackerrank.com/contests/sda-2020-2021-test1/challenges/1-257

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, M, num, biggest_num=0, sum=0;
    int arrN[100001]={0};
    int arrM[100001]={0};
    cin>>N;
    
    for(int i=0; i<N; i++){
        cin>>num;
        if(num>biggest_num){
            biggest_num=num;
        }
        arrN[num]++;
    }
    
    cin>>M;
    for(int i=0; i<M; i++){
        cin>>num;
        if(num>biggest_num){
            biggest_num=num;
        }
        arrM[num]++;
    }

    for(int i=0; i<=biggest_num; i++){
        if(arrN[i]!=0 && arrM[i]!=0 ){
            sum+=i;
        }
    }
    
    cout<<sum;
    return 0;
}
