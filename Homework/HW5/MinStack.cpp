//https://www.hackerrank.com/contests/sda-homework-5/challenges/minstack
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack> 

using namespace std;
void min()
{
    stack<int> mystack;
    stack<int> minstack;
    int N;
    cin >> N;
    if (N > 0) {
        for (int i = 0; i < N; i++)
        {
            string a;
            cin >> a;
            if (a == "push") {
                int x;
                cin >> x;
                mystack.push(x);
                if(minstack.empty())minstack.push(x);
                else {
                    if (x < minstack.top()) minstack.push(x);
                }
            }
            else {
                if (a == "pop") {
                    if (mystack.empty() || minstack.empty()) { cout << 0; }
                    else {
                        if (mystack.top() == minstack.top()) minstack.pop();
                        mystack.pop();
                    }
                }
                else {
                    if (a == "peek") cout << mystack.top() << endl;
                    else {
                        if (a == "min")cout << minstack.top() << endl;
                        else cout << 0;
                    }
                }
            }
        }
    }
    else cout << 0;
}

int main() {
    min();
    return 0;
}
