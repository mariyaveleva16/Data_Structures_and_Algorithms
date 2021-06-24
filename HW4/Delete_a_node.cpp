//https://www.hackerrank.com/contests/sda-homework-4/challenges/delete-a-node-from-a-linked-list
// Complete the deleteNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    if (position == 0)
    {
        SinglyLinkedListNode* temp;
        temp = head;
        if (head != nullptr) {
            head = head->next;
            delete temp;
            return head;
        }
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
    previous->next = current->next;
    delete current;
    return head;

}
