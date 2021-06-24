//https://www.hackerrank.com/contests/sda-homework-6/challenges/1-266
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 
 
void calculateGifts(vector<vector<int>>& vect, int ind, vector<int>& gifts) {
    int sum = 0;
    for (size_t i = 0; i < vect[ind].size(); i++) {
        calculateGifts(vect, vect[ind][i], gifts);
        sum += gifts[vect[ind][i]] + 1;
    }
    gifts[ind] = sum;
}
 
 
 
int main() {
    int N;
    cin >> N;
 
    vector<vector<int>>vect(N);
    vector<int>gifts(N);
    for (int i = 0; i < N-1; i++)
    {
        int ind, child;
        cin >> ind >> child;
        vect[ind].push_back(child);
    }
 
    calculateGifts(vect, 0, gifts);
    for (size_t i = 0; i < gifts.size(); i++)
    {
        cout << gifts[i] << " ";
    }
    return 0;
}
