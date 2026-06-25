/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *//* my version of the code
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int length=0;
        while(temp->next!=NULL)lenght++,temp=temp->next;
        int count =length-n;
        temp=head;
        ListNode prev=temp;

        for(int i=0;i<=count;i++){
        prev=temp;
        temp=temp->next;
        }
        prev->next=temp->next;
        delete temp;
        return head;
    }
};*/
/*using dummy*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode dummy(0);
         dummy.next=head;
         ListNode*first=&dummy;
         ListNode*second=&dummy;
         for(int i=1;i<=n+1;i++){
             first=first->next;
         }
         while(first!=nullptr){
             first=first->next;
             second=second->next;
         }
        ListNode* target = second->next;

        // Bypass target
        second->next = target->next;

        // Free memory
        delete target;

        return dummy.next;

    }
};