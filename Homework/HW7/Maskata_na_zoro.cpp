//https://www.hackerrank.com/contests/sda-homework-7/challenges/zoros-mask/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> value;
    vector<int> count;
   //int countD = 0;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        value.push_back(x);
        int counter=0;
        for (int i = 0; i < 32; i++) { 
        if(((x >> i) & 1) == 1)counter++;
        }
        count.push_back(counter);
        //cout<<count.back()<<endl;
    }
    int orNum=value[0];
    for(int i=0; i<n; i++)
    {
        orNum=orNum&value[i];
    }
    int orNumcount=0;
    for (int i = 0; i < 32; i++) { 
        if(((orNum >> i) & 1) == 1)orNumcount++;
        }
    //cout<<orNumcount<<endl;
    //orNumcount=32-orNumcount;
    //cout<<orNumcount<<endl;
    int tocout=0;
    for(int i=0;i<n;i++)
    {
        tocout=tocout+pow(2, count[i]);
       // cout<<tocout<<endl;
    }
    cout<<tocout-pow(2, orNumcount);
    /*int a,b;
    cin>>a>>b;
    int countF = 0; 
    int countS = 0; 
    
    for (int i = 0; i < 32; i++) { 
        if(((a >> i) & 1) == 1)countF++;
        if(((b >> i) & 1) == 1)countS++;
        if ((((a >> i) & 1) == ((b >> i) & 1))&&((a >> i) & 1) == 1)  {  
           countD++;    
        } 
    } 
    cout<<pow(2,countF)+pow(2,countS)-pow(2,countD);*/
    return 0;
}
