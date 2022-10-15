//https://www.hackerrank.com/contests/sda-homework-4/challenges/insert-a-node-at-a-specific-position-in-a-linked-list
// Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {

    if (position == 0)
    {
        SinglyLinkedListNode* newHead = new SinglyLinkedListNode(data);
        newHead->next = head;
        if (head != nullptr) {
            head = head->next;
        }
        head = newHead;
        return head;

    }
    SinglyLinkedListNode* current = head;
    SinglyLinkedListNode* previous = NULL;

    for (int i = 0; i < position; i++)
    {
        if (current->next != NULL)
        {
            previous = current;
            current = current->next;
        }
    }
    SinglyLinkedListNode* temp = new SinglyLinkedListNode(data);
    temp->next = current; 
    previous->next = temp;
    return head;
}
