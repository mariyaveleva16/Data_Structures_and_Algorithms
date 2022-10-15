//https://www.hackerrank.com/contests/sda-homework-4/challenges/challenge-2647
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = NULL;
    }
};

class SinglyLinkedList {
public:
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;

    SinglyLinkedList() {
        this->head = NULL;
        this->tail = NULL;
    }

    void insert_node(int node_data) {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

        if (!this->head) {
            this->head = node;
        }
        else {
            this->tail->next = node;
        }

        this->tail = node;
    }
};
int GetNth(SinglyLinkedListNode* head, int index)
{
    SinglyLinkedListNode* current = head;
    int count = 0;
    while (current != NULL) {
        if (count == index)
            return (current->data);
        count++;
        current = current->next;
    }
    return 0;
}
SinglyLinkedListNode* swapNodes(SinglyLinkedListNode* head_ref, int x, int y)
{
    if (x == y) return 0;
    SinglyLinkedListNode* prevX = NULL;
    SinglyLinkedListNode* currX = head_ref;
    while (currX && currX->data != x)
    {
        prevX = currX;
        currX = currX->next;
    }
    SinglyLinkedListNode* prevY = NULL;
    SinglyLinkedListNode* currY = head_ref;
    while (currY && currY->data != y)
    {
        prevY = currY;
        currY = currY->next;
    }
    if (currX == NULL || currY == NULL)
    {
        return 0;
    }
    if (prevX != NULL)
    {
        prevX->next = currY;
    }
    else
    {
        //cout << "1" << endl;
        head_ref = currY;
        //currY -> next = currX;
    }
    if (prevY != NULL)
    {
        prevY->next = currX;
    }
    else
    {
        cout << "2" << endl;
        head_ref = currX;
    }
    SinglyLinkedListNode* temp = currY->next;
    currY->next = currX;
    currX->next = temp;
    return head_ref;
}
void print_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        cout << node->data;
        node = node->next;
        if (node) {
            cout << "\n";
        }
    }
}

SinglyLinkedListNode* reverseNode(SinglyLinkedListNode* head, int x, int y, int N) {

    if (x > 0) {
        int i = 0;
        int j = x - 1;
        while (i <= N - x / 2) {
            if (i < j) { head =swapNodes(head, GetNth(head, i), GetNth(head, j)); i++; j--; }
            else { i = i + (x + 1) / 2 + y; j = i + x - 1;  if (j > N - 1)j = N - 1; }
        }
    }
    return head;
}
int main()
{

    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    int x, y;
    cin >> x;
    cin >> y;
    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        llist->insert_node(llist_item);
    }
    SinglyLinkedListNode* llist1 =reverseNode(llist->head, x, y, llist_count);

    print_singly_linked_list(llist1);
    cout << "\n";

    return 0;
}
