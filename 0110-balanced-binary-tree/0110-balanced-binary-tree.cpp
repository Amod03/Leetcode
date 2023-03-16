/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };>
 */
 #include<bits/stdc++.h>
class Solution {
private:
pair<bool,int>isBalanced3(TreeNode* root)
{
    if(root==NULL){
    pair<bool,int>p=make_pair(true,0);
    return p;
    }
pair<bool,int>left=isBalanced3(root->left);
pair<bool,int>right=isBalanced3(root->right);
bool leftAns=left.first;
bool rightAns=right.first;
bool diff=abs(left.second-right.second)<=1;
pair<bool,int>ans;
ans.second=max(left.second,right.second)+1;

if(leftAns && rightAns && diff)
ans.first=true;
else
ans.first=false;

return ans;
}

public:
    bool isBalanced(TreeNode* root) {
        return isBalanced3(root).first;
    }
};