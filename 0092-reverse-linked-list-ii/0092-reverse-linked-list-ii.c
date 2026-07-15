/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head == NULL || left == right)
        return head;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    for (int i = 1; i < left; i++) {
        prev = curr;
        curr = curr->next;
    }
    struct ListNode* connection = prev;
    struct ListNode* tail = curr;
    prev = NULL;
    for (int i = 0; i <= right - left; i++) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    if (connection != NULL)
        connection->next = prev;
    else
        head = prev;
    tail->next = curr;
    return head;
}