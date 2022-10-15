//https://www.hackerrank.com/contests/sda-homework-4/challenges/merge-two-sorted-linked-lists
// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if(head1==NULL)
    {
        return head2;
    }
    else{
        if(head2==NULL) return head1;
    }
    SinglyLinkedListNode* merge_head = NULL;
    if(head1->data <= head2->data)
    { 
        merge_head = head1;
        head1 = head1->next;
    }
    else
    {
        merge_head = head2;
        head2 = head2->next;
    }
    SinglyLinkedListNode* merge_tail = merge_head;
    while(head1!= NULL && head2!=NULL)
    {
        SinglyLinkedListNode* temp = NULL;
        if (head1->data <= head2->data) 
        {
            temp = head1;
            head1 = head1->next;
        } 
        else 
        {
            temp = head2;
            head2 = head2->next;
        }

        merge_tail->next = temp;
        merge_tail = temp;
    }
    if (head1 != NULL) 
    {
        merge_tail->next = head1;
    } 
    else if (head2 != NULL) {
        merge_tail->next = head2;
    }
    return merge_head;

}
