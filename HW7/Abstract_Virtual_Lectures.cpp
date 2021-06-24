//https://www.hackerrank.com/contests/sda-homework-7/challenges/avl-delete
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
  
struct Node
{
    int value;
    Node* left;
    Node* right;
    int height;
};

int height(Node* current)
{
    if (current == NULL)
    {
        return 0;
    }    
    return current->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

Node* newNode(int value)
{
    Node* node = new Node();
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return(node);
}

Node* rightRotate(Node* current)
{
    Node* cLeft = current->left;
    Node* tree = cLeft->right;
    cLeft->right = current;
    current->left = tree; 
    current->height = max(height(current->left), height(current->right)) + 1;
    cLeft->height = max(height(cLeft->left), height(cLeft->right)) + 1;
    return cLeft;
}
 
Node* leftRotate(Node* current)
{
    Node* cRight = current->right;
    Node* tree = cRight->left;
    cRight->left = current;
    current->right = tree;  
    current->height = max(height(current->left), height(current->right)) + 1;
    cRight->height = max(height(cRight->left), height(cRight->right)) + 1; 
    return cRight;
}
  
int getBalance(Node* current)
{
    if (current == NULL)
    {
        return 0;
    }
    return height(current->left) - height(current->right);
}

Node* insert(Node* node, int value)
{
    if (node == NULL)
    {
        return(newNode(value));
    }
    if (value < node->value)
    {
        node->left = insert(node->left, value);
    }
    else {
        if (value > node->value)
        {
            node->right = insert(node->right, value);
        }
        else
        {
            return node;
        }
    }
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node); 
    if (balance > 1 && value < node->left->value)
    {
        return rightRotate(node);
    }
    if (balance < -1 && value > node->right->value)
    {
        return leftRotate(node);
    }
    if (balance > 1 && value > node->left->value)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && value < node->right->value)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

Node* minNode(Node* node)
{
    Node* current = node;
    while (current->left != NULL) 
    {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int value)
{
    if (root == NULL)
    {
        return root;
    }
    if (value < root->value)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            Node* temp = root->left ? root->left: root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
        }
        else
        { 
            Node* temp = minNode(root->right); 
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
    }
    if (root == NULL)
    {
        return root;
    }
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
    {
        return rightRotate(root);
    }
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    } 
    if (balance < -1 && getBalance(root->right) <= 0)
    {
        return leftRotate(root);
    }
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->value<<" ";
        inorder(root->right);
    }
}

int main()
{
    Node* root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string comand;
        cin >> comand;
        if (comand == "add") {
            int x;
            cin >> x;
            root = insert(root, x);
        }
        else {
            if (comand == "del")
            {
                int x;
                cin >> x;
                root = deleteNode(root, x);
            }
            else
            {
                inorder(root);
                cout << "\n";
            }
        }
    }
    return 0;
}
