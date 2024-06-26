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
private:
ListNode* getMiddle(ListNode* head)
{
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

private:
ListNode* reverse(ListNode* head)
{
    ListNode* temp=head;
    ListNode* prev=NULL;
    while(temp){
        ListNode* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
    
}

public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
        {
            return true;
        }
        ListNode* middle=getMiddle(head);

        ListNode* temp=middle->next;
        middle->next=reverse(temp);

        ListNode* head1=head;
        ListNode* head2=middle->next;

        while(head2!=NULL)
        {
            if(head1->val != head2->val)
            return false;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
};