//https://www.hackerrank.com/contests/sda-homework-2/challenges/who-wants-to-be-a-palindrome-intro-sorting
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define NO_OF_CHARS 256 
void canFormPalindrome()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int count[NO_OF_CHARS] = { 0 };
        string str;
        cin >> str;
        for (int i = 0; str[i]; i++)
        {
            count[str[i]]++;
        }
        int odd = 0;
        for (int i = 0; i < NO_OF_CHARS; i++)
        {
            if (count[i] & 1)
                odd++;
        }
        if (odd > 1)
                cout<< "FALSE\n";
        else cout<< "TRUE\n";
    }
}


int main()
{
    canFormPalindrome();
}
