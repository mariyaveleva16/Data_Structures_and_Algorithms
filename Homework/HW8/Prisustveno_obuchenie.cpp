//https://www.hackerrank.com/contests/sda-homework-8/challenges/challenge-2728
#include <iostream> 
#include<set>
#include<vector>
#include<queue>
#include<functional>
 
using namespace std;
 
int getRooms(multiset<pair<int, bool>>& s) {
    int count = 0;
    int cur = 0;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (it->second == true) {
            cur++;
        }
        else {
            cur--;
        }
        if (count < cur)count = cur;
    }
    return count;
}
int main() {
 
    multiset<pair<int, bool>> s;
    int n;
    cin >> n;
    int start, end;
    for (int i = 0; i < n; i++)
    {
        cin >> start >> end;
        s.insert({end,false});
        s.insert({start,true});
    }
    cout << getRooms(s);
    return 0;
}
