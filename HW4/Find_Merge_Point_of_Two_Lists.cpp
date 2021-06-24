//https://www.hackerrank.com/contests/sda-homework-4/challenges/find-the-merge-point-of-two-joined-linked-lists
// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int count_List(SinglyLinkedListNode* head)  
{  
    int count = 0; 
    SinglyLinkedListNode* current = head; 
    while (current != NULL)  
    {  
        count++;  
        current = current->next;  
    }  
    return count;  
}  
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* current1 = head1; 
    SinglyLinkedListNode* current2 = head2; 
    int c1 = count_List(head1); 
    int c2 = count_List(head2); 
    int d = abs(c1-c2); 
    for (int i = 0; i < d; i++) { 
        if(c1>c2) current1 = current1->next; 
        else current2 = current2->next; 
    } 
  
    while (current1 != NULL && current2 != NULL) { 
        if (current1 == current2) 
            return current1->data; 
        current1 = current1->next; 
        current2 = current2->next; 
    } 
    return -1;

}
