//https://www.hackerrank.com/contests/sda-2020-2021-test3-trvdd/challenges
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid; 
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
void rotate()
{
    int N;
    cin >> N;
    int* arr;
    arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int Q;
    cin >> Q;
    int* arr2;
    arr2 = new int[Q];
    for (int i = 0; i < Q; i++)
    {
        cin >> arr2[i];
        cout<< binarySearch(arr, 0, N, arr2[i])<<"\n";
    }
   
}

int main() {
    rotate();
    return 0;
}
