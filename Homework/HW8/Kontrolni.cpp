//https://www.hackerrank.com/contests/sda-homework-8/challenges/challenge-2727
#include <vector>
#include<iostream>
#include<iomanip>
#include <set>
#include<queue>
#include<cmath>
#include<algorithm>
 
using namespace std;
 
 
void solve(vector<pair<long long, long long>>& vect) {
    priority_queue <pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>> > pq;
 
    size_t index = 0;
    multiset<pair<long long, long long>> s;
    long long waitingTime = 0;
    long long startTime = 0;
    while (index < vect.size()) {
        pq.push({ vect[index].second, vect[index].first });
 
        startTime = vect[index].first;
        index++;
 
        while (!pq.empty()) {
            pair<long long, long long> element = pq.top();
            pq.pop();
 
            waitingTime += (startTime - element.second) + element.first;
 
            while (index < vect.size() && vect[index].first <= startTime + element.first) {
                pq.push({ vect[index].second, vect[index].first });
                index++;
            }
 
            startTime += element.first;
        }
    }
    if (vect.size() != 0) {
        cout << waitingTime / vect.size();
    }
}
int main() {
    int N;
    cin >> N;
 
    vector<pair<long long, long long>> vect;
 
    for (int i = 0; i < N; i++)
    {
        long long start, lines;
        cin >> start >> lines;
        vect.push_back({ start,lines});
    }
 
    sort(vect.begin(), vect.end());
    solve(vect);
 
    return 0;
}
