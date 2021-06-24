//https://www.hackerrank.com/contests/sda-homework-5/challenges/trucks
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
void reverseStack(stack<int>& mystack)
{
    int item;
    stack<int> tmpStack;

    while (mystack.empty() == false)
    {
        item = mystack.top();
        mystack.pop();
        tmpStack.push(item);
    }
    while (tmpStack.empty() == false)
    {
        item = tmpStack.top();
        tmpStack.pop();
        cout << item << " ";

    }
    return;
}
void kamioni()
{
    int N;
    cin >> N;
    stack<int> mystack;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        if (x > 0) mystack.push(x);
        else
        {
            while (mystack.empty() == false && mystack.top() < -x && mystack.top()>0)
            {
                mystack.pop();
            }
            if (mystack.empty()|| mystack.top()<0) mystack.push(x);
            else { if (mystack.top() == -x) mystack.pop(); }
        }
    }
    if (mystack.empty());
    else {
        reverseStack(mystack);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    kamioni();
    return 0;
}
