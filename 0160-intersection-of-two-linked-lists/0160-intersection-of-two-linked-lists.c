/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *h1 = headA;
    struct ListNode *h2 = headB;
    while(h1!=h2){
        if(h1==NULL) h1=headB;
        else h1=h1->next;
        if(h2==NULL) h2=headA;
        else h2=h2->next;
    }
    return h1;

}