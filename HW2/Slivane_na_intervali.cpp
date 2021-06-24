//https://www.hackerrank.com/contests/sda-homework-2/challenges/merge-intervals42/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Interval
{
    int start, end;
};
bool sortInterval(Interval first, Interval second)
{
    return (first.start < second.start);
}
void manageIntervals()
{
    int N;
    cin >> N;
    Interval* arr;
    arr = new Interval[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].start >> arr[i].end;
    }
    sort(arr, arr + N, sortInterval);
    vector<Interval> my_vector;
    my_vector.push_back(arr[0]);
    for (int i = 1; i < N; i++)
    {
        Interval last = my_vector.back();
        if (last.end < arr[i].start)
        {
            my_vector.push_back(arr[i]);
        }
        else if (last.end < arr[i].end)
        {
            last.end = arr[i].end;
            my_vector.pop_back();
            my_vector.push_back(last);
        }
    }
    for (int i = 0; i < my_vector.size(); i++)
    {
        cout << my_vector[i].start<<" "<< my_vector[i].end<<"\n";
    }
}
int main()
{
    manageIntervals();
}
