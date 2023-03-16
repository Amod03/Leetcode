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
public:
     int find(TreeNode* root,int mx)
     {
         if(root==NULL)
         return 0;
         mx=max(mx,root->val);
         int x=find(root->left,mx);
         int y=find(root->right,mx);
         int z=0;
         if(mx<=root->val)
         z= 1;
         else 
         z= 0;
         return x+y+z;
     }
    int goodNodes(TreeNode* root) {
        return find(root,root->val);
    }
};