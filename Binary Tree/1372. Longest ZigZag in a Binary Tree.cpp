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

    int helper(TreeNode* root, bool right, int path){
        if(!root){
            return 0;
        }
        if(right){
            return max(path, max(helper(root->left, false, path+1), helper(root->right, true, 1)));
        }else{
            return max(path, max(helper(root->right, true, path+1), helper(root->left, false, 1)));
        }
        return 0; 
    }

    int longestZigZag(TreeNode* root) {
        if(!root){
            return 0; 
        }
        return max(helper(root, true, 0), helper(root, false, 0));
    }
};