struct ListNode* reverse(struct ListNode* head){
    struct ListNode *prev = NULL;
    struct ListNode *temp = head;
    struct ListNode *next;
    while(temp != NULL){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}
int pairSum(struct ListNode* head){
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *revhead = reverse(slow->next);
    slow->next = NULL;
    int max = 0;
    while(revhead != NULL){
        if(max < revhead->val + head->val){
            max = revhead->val + head->val;
        }
        revhead = revhead->next;
        head = head->next;
    }
    return max;
}