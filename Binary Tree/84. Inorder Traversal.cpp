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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> list;
        helper(root, list);
        return list; 
    }
    
    void helper(TreeNode* root, vector<int>& list){
        if(root == NULL){
            return;
        }
        helper(root->left, list);
        list.push_back(root->val);
        helper(root->right, list);
    }
};