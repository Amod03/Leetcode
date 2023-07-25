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

bool isValid(TreeNode* root,long high,long low)
{
	if(root==NULL)
	return true;
	if(root->val>=high || root->val<=low)
	return false;
	return isValid(root->left,root->val,low) && isValid(root->right, high, root->val);
}
bool isValidBST(TreeNode *root) {
	return isValid(root,LONG_MAX,LONG_MIN);
}
};