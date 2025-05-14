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
    ListNode* findmid(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL )
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left,ListNode* right)
    {
        if(left==NULL)
        return right;
        if(right==NULL)
        return left;
        ListNode* ans1=new ListNode(-1);
        ListNode* temp=ans1;
        while(left!=NULL && right!=NULL)
        {
            if(left->val<right->val)
            {
                temp->next=left;
               temp=left;
                left=left->next;
            }
            else{
                temp->next=right;
                temp=right;
                right=right->next;
            }
        }
          if(left)temp->next=left;
        else
            temp->next=right;
            ListNode* ans2=ans1->next;
            return ans2;
        
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;

        ListNode* mid=findmid(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;

        left=sortList(left);
        right=sortList(right);
        ListNode* result=merge(left,right);
        return result;
    }
};