//https://www.hackerrank.com/contests/sda-homework-13/challenges/all-paths42
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;
#define N 25
 
bool validRoom(int x, int y, int rows, int cols)
{
    if ( x >= rows || y >= cols || x < 0 || y < 0 ) return false;
    return true;
}
 
void countPaths(char maze[N][N], int x, int y, int rows, int cols, int visited[N][N], int& count, int countRooms, int xRooms)
{
    if (maze[x][y] == 'e' && countRooms == ((rows * cols) - (2 + xRooms)))
    {
        count++;
        return;
    }
    visited[x][y] = 1;
 
    if (validRoom(x, y, rows, cols) && maze[x][y] != 'x')
    {
        if (maze[x][y] == '-')
        {
            countRooms++;
        }
        if (x < rows - 1 && !visited[x + 1][y])
        {
            countPaths(maze, x + 1, y, rows, cols, visited, count, countRooms, xRooms);
        }
        if (y < cols - 1 && !visited[x][y + 1])
        {
            countPaths(maze, x, y + 1, rows, cols, visited, count, countRooms, xRooms);
        }
        if (x - 1 >= 0 && !visited[x - 1][y])
        {
            countPaths(maze, x - 1, y, rows, cols, visited, count, countRooms, xRooms);
        }
        if (y - 1 >= 0 && !visited[x][y - 1])
        {
            countPaths(maze, x, y - 1, rows, cols, visited, count, countRooms, xRooms);
        }
    }
    visited[x][y] = 0;
}
 
int main()
{
    int rows, cols, startRow = 0, startCols = 0, xRooms = 0;
    char maze[N][N];
    cin >> rows >> cols;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 's')
            {
                startRow = i;
                startCols = j;
            }
            if (maze[i][j] == 'x')
            {
                xRooms++;
            }
        }
    }
    int count = 0;
    int countRooms = 0;
    int visited[N][N];
 
    memset(visited, 0, sizeof visited);
 
    countPaths(maze, startRow, startCols, rows, cols, visited, count, countRooms, xRooms);
 
    cout << count;
 
    return 0;
}
