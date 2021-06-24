//https://www.hackerrank.com/contests/sda-homework-6/challenges/top
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int SIZE = 2000000;
const int SIZE_DEPTH = 1000000;
vector<pair<int, int>> container(SIZE);
 
void function(vector<pair<int,int>>& Vector, int i, int depth, int position)
{
    if (container[position].first < 0 || container[position].second > depth)
    { 
        container[position] = { i, depth };
    }
 
    if (Vector[i].first != -1)
    {
        function(Vector, Vector[i].first,depth+1, position - 1);
    }
 
    if (Vector[i].second != -1)
    {
        function(Vector,Vector[i].second,depth+1, position + 1);
    }
}
 
int main() {
 
 
    int k=0;
    while(k < SIZE)
    {
        container[k].first = -1;
        container[k].second = SIZE_DEPTH;
        k++;
    }
 
    int N;
    cin >> N;
    vector<pair<int, int>> Vector(N);
 
    int j=0;
    while( j< N)
    {
        int x, y;
        cin >> x >> y;
        Vector[j] = { x,y };
        j++;
    }
    function(Vector,0,0, SIZE/2);
 
    int i =0;
    while( i < SIZE)
    {
        if (container[i].first != -1)
        {
            cout << container[i].first << " ";
        }
        i++;
    }
    return 0;
}
