/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *prev = &dummy;
    struct ListNode *curr = head;
    while(curr != NULL){
        if(curr->next != NULL && curr->val == curr->next->val){
            while(curr->next != NULL && curr->val == curr->next->val)
                curr = curr->next;
            prev->next = curr->next;
        }else{
            prev = prev->next;
        }
        curr = curr->next;
    }
    return dummy.next;
}