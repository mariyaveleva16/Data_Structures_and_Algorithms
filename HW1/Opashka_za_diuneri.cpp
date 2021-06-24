#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>

using namespace std;

int distance(int N, char* arr)
{
    if (N == 0) return 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if ((arr[i] != '-') && (arr[i] != 'x')) return 0;
    }
    int max_distance = 0;
    int temp_distance = 0;
    int s = -1;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == '-') {
            
            temp_distance++;
        }
        else {
            if (temp_distance > max_distance) {
                max_distance = temp_distance;
                s = i - temp_distance;
            }
            temp_distance = 0;
        }
    }
    if(max_distance == 0 && temp_distance == 0) return -1;
    if(s==0) return max_distance-1;
    if(max_distance == 0 && temp_distance !=0) return temp_distance-1;
    if(max_distance%2==0) return max_distance/2 - 1;
    else return (max_distance-1)/2;
}

int main()
{
    int N;
    cin >> N;
    char* arr;
    arr = new char[N];
    cout << distance(N, arr);
}
