//https://www.hackerrank.com/contests/sda-homework-10/challenges/challenge-2753
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int Ncurr_x, Mcurr_x, Ncurr_y, Mcurr_y;
void dfs(vector<vector<char>>& grid, int x, int y)
{
    grid[x][y] = '2';
    if (x + 1 < grid.size() && grid[x + 1][y] == '1')
    {
        if (Mcurr_x < x + 1) Mcurr_x = x + 1;
        dfs(grid, x + 1, y);
    }
    if (x - 1 >= 0 && grid[x - 1][y] == '1')
    {
        if (Ncurr_x > x - 1) Ncurr_x = x - 1;
        dfs(grid, x - 1, y);
    }
    if (y - 1 >= 0 && grid[x][y - 1] == '1')
    {
        if (Ncurr_y > y - 1) Ncurr_y = y - 1;
        dfs(grid, x, y - 1);
    }
    if (y + 1 < grid.size() && grid[x][y + 1] == '1')
    {
        if (Mcurr_y < y + 1) Mcurr_y = y + 1;
        dfs(grid, x, y + 1);
    }
}
void numIslands(vector<vector<char>>& grid)
{
    int H = grid.size();
    vector<int> S;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < H; j++)
        {
            if (grid[i][j] == '1')
            {
                Ncurr_x = i;
                Mcurr_x = i;
                Ncurr_y = j;
                Mcurr_y = j;
                dfs(grid, i, j);
                S.push_back((Mcurr_x - Ncurr_x + 1) * (Mcurr_y - Ncurr_y + 1));
            }
        }
    }
    sort(S.begin(), S.end(), greater<int>());
    for (auto x : S)
        cout << x << " ";
}

int main()
{
    int N;
    cin >> N;
    vector<vector<char>> grid;
    for (int i = 0; i < N; i++)
    {
        vector<char> myvector;
        for (int j = 0; j < N; j++)
        {
            char tempVal;
            cin >> tempVal;
            myvector.push_back(tempVal);
        }
        grid.push_back(myvector);
    }
    numIslands(grid);
}
