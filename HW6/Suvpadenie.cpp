//https://www.hackerrank.com/contests/sda-homework-6/challenges/match-2
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
    bool isWord;
    Node* chidren[26];
    Node() {
        isWord = false;
        for (int i = 0; i < 26; i++)
        {
            chidren[i] = nullptr;
        }
    }
};
Node* root;
void addWord(string word)
{
    Node* node = root;
    for (char letter : word)
    {
        if (node->chidren[letter - 'a'] == nullptr) {
            node->chidren[letter - 'a'] = new Node();
        }
        node = node->chidren[letter - 'a'];
    }
    node->isWord = true;
}
bool findWord(string word)
{
    Node* node = root;
    for (char letter : word) {
        if (node->chidren[letter - 'a'] == nullptr) return false;
        node = node->chidren[letter - 'a'];
    }
    return node->isWord;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    root = new Node();
    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        addWord(word);
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        string word;
        cin >> word;
        if (findWord(word) == true) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
