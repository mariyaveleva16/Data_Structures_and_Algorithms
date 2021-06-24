//https://www.hackerrank.com/contests/sda-2020-2021-test2-erfdw/challenges/challenge-2676
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void folders()
{
    int N;
    cin >> N;
    int* arr;
    arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i < N; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    vector <int>my_vector;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] != arr[i + 1]) my_vector.push_back(arr[i]);
    }
    for (int i = 0; i < my_vector.size(); i++)
    {
        cout << my_vector[i] << " ";
    }
}

int main() {

    folders();
    return 0;
}
