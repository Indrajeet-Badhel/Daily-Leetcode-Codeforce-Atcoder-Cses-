/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* merge(struct ListNode* left, struct ListNode* right)
{
    struct ListNode dummy;
    struct ListNode* tail = &dummy;

    dummy.next = NULL;

    while (left && right)
    {
        if (left->val <= right->val)
        {
            tail->next = left;
            left = left->next;
        }
        else
        {
            tail->next = right;
            right = right->next;
        }

        tail = tail->next;
    }

    if (left)
        tail->next = left;
    else
        tail->next = right;

    return dummy.next;
}

struct ListNode* sortList(struct ListNode* head)
{
    // Base case
    if (head == NULL || head->next == NULL)
        return head;

    // Find middle
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev = NULL;

    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split into two lists
    prev->next = NULL;

    // Sort both halves
    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(slow);

    // Merge sorted halves
    return merge(left, right);
}