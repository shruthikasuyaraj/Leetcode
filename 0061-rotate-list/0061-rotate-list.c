/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || k == 0)
        return head;
    int len = 1;
    struct ListNode* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
        len++;
    }
    struct ListNode* temp = head;
    k=k%len;
    if (k == 0)
        return head;
    for(int i=1;i<len-k;i++){
        temp = temp->next;
    }
    struct ListNode* newhead = temp->next;
    temp->next = NULL;
    tail->next = head;
    return newhead;
}