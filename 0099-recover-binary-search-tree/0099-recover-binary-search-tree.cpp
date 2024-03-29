/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
    
public:
void inorder(TreeNode* root)
{
   if(root==NULL)
   return;
   inorder(root->left);

   if (root->val<prev->val)
   {
       //if this is first violation,mark these two nodes AS first and middle
       if(first==NULL)
       {
           first=prev;
           middle=root;
       }
       //if this is second violation ,mark this node as last
       else
       last=root;
   }
   //mark this node as previous
   prev=root;
   inorder(root->right);
}
    void recoverTree(TreeNode* root) {
        first=middle=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first && last)
        swap(first->val,last->val);
        else if(first &&  middle)
        swap(first->val,middle->val);
    }
};