//https://www.hackerrank.com/contests/sda-2020-2021-test5-trgdcw/challenges/challenge-2712
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
void sum()
{
    deque<int> mydeque;
    deque<int> mydeque2;
    deque<int> mydeque3;
    int sum = 0;
    int temp=0;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        if (x >= 0) { mydeque.push_back(x); sum = sum + x; }
        else {
            if (x == -1 && !mydeque.empty()) {
                temp = mydeque.back();
                mydeque3.push_back(temp);
                sum = sum - temp;
                mydeque.pop_back();
                mydeque2.push_back(x);
                
            }
            else {
                if (x == -2 && !mydeque2.empty()&& mydeque2.back() == -1 ) {
                    mydeque2.pop_back();
                    //mydeque2.push_back(x);
                    mydeque.push_back(mydeque3.back());
                    sum = sum + mydeque3.back();
                    mydeque3.pop_back();
                }
            }
        }
    }
    cout << sum << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    sum();
    return 0;
}
