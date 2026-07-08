/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *fast = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *slow = (struct ListNode*)malloc(sizeof(struct ListNode));
    fast=head;
    slow=head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}