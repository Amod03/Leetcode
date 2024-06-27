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
void level(TreeNode*root,vector<vector<int>>&v){
   queue<TreeNode*>q;
   if(root==NULL)
   return;
   q.push(root);
   vector<int>v1;
   while (!q.empty()) {
            int size = q.size(); 
            vector<int> level; 

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); 
                q.pop(); 
                level.push_back(node->val); 
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            // Store the current level
            // in the answer vector
            v.push_back(level); 
        }

}
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>v;
        level(root,v);
        return v;
    }
};