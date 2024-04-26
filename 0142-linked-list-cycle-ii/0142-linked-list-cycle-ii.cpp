/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {

    private:
      ListNode* floydCycle(ListNode*head)
      {
         if(head==NULL)
        return NULL;
        if(head->next==NULL)
        return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)
            {
                return slow;
            }
        }
        return NULL;
      }
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
        return NULL;
     ListNode* Intersection=floydCycle(head);
     ListNode* slow=head;
     if(Intersection==NULL)
     return NULL;
     else{
         while(slow!=Intersection)
         {
             slow=slow->next;
             Intersection=Intersection->next;
         }
         return slow;
     }
    }
};