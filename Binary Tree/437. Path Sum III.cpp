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
    void helper(vector<int> path, int targetSum, int& total, TreeNode* root){
        if(!root){
            return; 
        }
        // add node to path 
        path.push_back(root->val);
        // check if target sum - root->val is possible, add to path and splice path array
        long curr = 0;
        for(int i = path.size()-1; i >= 0; i--){
            curr += path[i];
            if(curr == targetSum){
                total += 1; 
            }
        }
        helper(path, targetSum, total, root->left);
        helper(path, targetSum, total, root->right);
    }
 
    int pathSum(TreeNode* root, int targetSum) {
        int total = 0;
        vector<int> path;
        helper(path, targetSum, total, root);

        return total; 
    }
};