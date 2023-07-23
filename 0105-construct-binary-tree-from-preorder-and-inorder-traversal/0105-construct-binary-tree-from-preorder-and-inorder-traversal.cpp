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
    void createMapping(vector<int>in,map<int,int>&nodeToIndex,int n)
    {
        for(int i=0;i<n;i++)
        {
            nodeToIndex[in[i]]=i;
        }
    }

    TreeNode* solve(vector<int>in,vector<int>pre,int &index,int inOrderStart,int inOrderEnd,int n,map<int,int>&nodeToIndex)
    {
        if(index>=n || inOrderStart>inOrderEnd)
        {
            return NULL;
        }
        int element=pre[index++];
        TreeNode* root=new TreeNode(element);
        int position=nodeToIndex[element];
        root->left=solve(in,pre,index,inOrderStart,position-1,n,nodeToIndex);
        root->right=solve(in,pre,index,position+1,inOrderEnd,n,nodeToIndex);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex=0;
        int n=inorder.size();
        map<int,int>nodeToIndex;
        createMapping(inorder,nodeToIndex,n);
        TreeNode* ans=solve(inorder,preorder,preOrderIndex,0,n-1,n,nodeToIndex);
        return ans;
    }
};