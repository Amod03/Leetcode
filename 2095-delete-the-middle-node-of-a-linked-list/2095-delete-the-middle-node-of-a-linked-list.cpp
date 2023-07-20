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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL)
        return NULL;
        ListNode* dummy=new ListNode(-1,head);
        ListNode * mid=dummy;
        ListNode * fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        mid=mid->next;
    }
    mid->next=slow->next;
    return dummy->next;
    }
};