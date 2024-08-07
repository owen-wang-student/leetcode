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
    void traverse(int& count, int pathMax, TreeNode* root){
        if(!root){
            return;
        }
        if(root->val >= pathMax){
            pathMax = root->val; 
            count += 1; 
        }
        traverse(count, pathMax, root->right);
        traverse(count, pathMax, root->left);
    }

    int goodNodes(TreeNode* root) {
        int count = 1; 
        if(!root){
            return 0; 
        }
        traverse(count, root->val, root->right);
        traverse(count, root->val, root->left);
        return count; 
    }
};