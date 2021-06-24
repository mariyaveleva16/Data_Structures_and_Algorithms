//https://www.hackerrank.com/contests/sda-homework-4/challenges/challenge-2685
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
    int data;
    Node* next = NULL;
    Node(int data, Node* next = NULL)
    {
        this->data = data;
        this->next = next;
    }
};
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }
    
    void push_back(int number) {
        Node* node = new Node(number);

    if (!this->head) {
        this->head = node;
    }
    else {
        this->tail->next = node;
    }

    this->tail = node;
    }
    void delete_first()
    {
        Node* temp;
        temp = head;
        if (head != NULL) {
            head = head->next;
            delete temp;
        }
    }
    
    
    int count_List(Node* head)
    {
        int count = 0;
        if (head != NULL) {
            Node* current = head;
            while (current != NULL)
            {
                count++;
                current = current->next;
            }
        }
        return count;
    }
};
Node* delNode(Node* head) {
    if (head->next == NULL)
    {
        Node* temp;
        temp = head;
        if (head != nullptr) {
            head = head->next;
            delete temp;
            return head;
        }
    }
    Node* current = head;
    Node* previous = NULL;
    for (int i = 0; current->next != NULL; i++)
    {
        if (current->next != NULL)
        {
            previous = current;
            current = current->next;
        }
    }
    previous->next = current->next;
    delete current;
    return head;
}
void print_singly_linked_list(Node* node) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << " ";
        }
    }
}
void kontrolno()
{
    LinkedList* list = new LinkedList();

    int list_count;
    cin >> list_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int count=0;
    for (int i = 0; i < list_count; i++) {
        string list_item;
        cin >> list_item;
        if (list_item == "add")
        {
            int x;
            cin >> x; 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            list->push_back(x);
            count++;
        }
        else
        {
            if (list_item == "gun") {
                list->head = delNode(list->head);
                count--;
            }
            else 
            {
                if(count==3||count==2)
                {
                    int t = list->head->data;
                    list->delete_first();
                    list->push_back(t);
                }
                else
                {
                    int t = list->head->data;
                    list->delete_first();
                    list->push_back(t);
                    int q = list->head->data;
                    list->delete_first();
                    list->push_back(q);
                }
            }
        }
    }
    if (list->head == NULL) {
       
        cout << 0;
    }
    else {
        cout << count << "\n";
        print_singly_linked_list(list->head);
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    kontrolno();
    return 0;
}
