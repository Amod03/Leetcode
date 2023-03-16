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
    int ans=0;  
    int find(TreeNode *root,int p,int gp)
    {
        if(root==NULL)
            return 0;
        if(gp%2==0)
            ans=ans+root->val;
        
        find(root->left,root->val,p);
        find(root->right,root->val,p);
        return ans;
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        int p=-1;
        int gp=-1;
        return find(root,p,gp);
        
    }
};