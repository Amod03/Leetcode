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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* first=head;
        ListNode* second=head->next;
        ListNode* sh2=second;
        while(second && second->next)
        {
            first->next=first->next->next;
            second->next=second->next->next;
            first=first->next;
            second=second->next;
        }
      first->next=sh2;
        return head;
    }
};