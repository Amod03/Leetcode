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
    ListNode* rotateRight(ListNode* head, int k) {
        int count=0;
        ListNode* temp=head;
        ListNode* temp2=head;
        
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        if(count==0)
        return head;
        int rotate=k%count;
        if(rotate==0)
        return head;
        else{
            temp=head;
            //cout<<temp->val<<endl;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=temp2;
           // cout<<temp->next->val<<endl;
            temp=head;
            int move=count-rotate;
            while(move-1>0)
            {
              temp=temp->next;
              move--;
            }
            //cout<<temp->val<<endl;
            temp2=temp->next;
            temp->next=NULL;
            //cout<<temp2->next->next<<endl;
        }
        return temp2;
    }
};