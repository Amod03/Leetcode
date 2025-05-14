/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {

    private:
    void insert(Node* &head,Node* &tail,int d)
    {
        Node* newNode=new Node(d);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=newNode;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        Node* temp=head;
        while(temp!=NULL){
        insert(cloneHead,cloneTail,temp->val);
        temp=temp->next;
    }
    Node* originalNode=head;
    Node* cloneNode=cloneHead;
    while(originalNode!=NULL && cloneNode!=NULL)
    {
        Node* next=originalNode->next;
        originalNode->next=cloneNode;
        originalNode=next;
        next=cloneNode->next;
        cloneNode->next=originalNode;
        cloneNode=next;
    }
    Node* temp1=head;
    while(temp1!=NULL)
    {
        if(temp1->next!=NULL)
        {
            temp1->next->random=temp1->random?temp1->random->next:temp1->random;
        }
        temp1=temp1->next->next;
    }

    originalNode=head;
    cloneNode=cloneHead;
    while(originalNode!=NULL && cloneNode!=NULL)
    {
        originalNode->next=cloneNode->next;
        originalNode=originalNode->next;
        if(originalNode!=NULL)
        {
            cloneNode->next=originalNode->next;
        }
        cloneNode=cloneNode->next;
    }
    return cloneHead;
    }
};