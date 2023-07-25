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
    TreeNode* kth(TreeNode* root,int &k)
{
	if(root==NULL)
	return NULL;
	
	TreeNode* left=kth(root->left,k);
	if(left!=NULL)
	return left;
	k--;
	if(k==0)
	return root;
	
	return kth(root->right,k);
}
public:
    int kthSmallest(TreeNode* root, int k) {
     TreeNode* small=kth(root,k);
        return small->val;
    }
};