#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int buy(int N, int* arr)
{
    if (N == 0) return 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int new_profit = 0;
    int temp = arr[0];
    int index = 0;
    int profit = 0;

    for (int i = 1; i < N; i++) {
        if (temp > arr[i]) {
            temp = arr[i];
            index = i;
        }
        if ((index == N - 1) && (profit == 0))  return 0;
        if ((arr[i] > arr[i + 1])) {
            new_profit = arr[i] - arr[index];
            index = i + 1;
            profit = profit + new_profit;
        }

    }
    return profit;
}

int main()
{
    int N;
    cin >> N;
    int* arr = new int[N];
    cout << buy(N, arr);
}
