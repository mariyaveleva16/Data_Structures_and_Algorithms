//https://www.hackerrank.com/contests/sda-2020-2021-test6-dbr8t-r/challenges/traversal-level-order
#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *left;
    Node *right;
    int value;
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void printSFB() {
      bool leftside = true;
 
        if (root==nullptr) 
            return;
 
        stack<Node*> cur;
        stack<Node*> next;
 
        cur.push(root);
 
        while (!cur.empty())
        { 
            Node* temp = cur.top();
            cur.pop();
 
            if (temp!=nullptr)
            { 
                cout << temp->value << " "; 
 
                if (leftside==true)
                { 
                    if (temp->left)
                        next.push(temp->left);
                    if (temp->right)
                        next.push(temp->right);
                } 
            else
            { 
                if (temp->right) 
                    next.push(temp->right); 
                if (temp->left) 
                    next.push(temp->left); 
            } 
        } 
            if (cur.empty())
            {
                leftside = !leftside;
                swap(cur, next);
            } 
        }
    }

private:
  	//you can write helper functions if needed
    Node* root;

    Node* insert(Node *curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        } else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        } else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        } else {
            //if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};

int main() {
    int n;
    cin >> n;
    int value;
    BST tree;
    for(int i = 0 ; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }
  
    tree.printSFB();
    return 0;
}
