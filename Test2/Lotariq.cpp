//https://www.hackerrank.com/contests/sda-2020-2021-test2-erfdw/challenges/challenge-2677
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool sortSums(int first, int second)
{
    return (first > second);
}
void lotary()
{
    int N;
    cin >> N;
    int* arr;
    arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N, sortSums);
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

}
int main() {

    lotary();
    return 0;
}
