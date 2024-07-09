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
    
    bool helper(TreeNode* root,long long minV = -10000000000 , long long maxV = 10000000000){
        if(root == NULL){
            return true; 
        } 

        bool left = helper(root->left, minV, root->val);
        bool right = helper(root->right, root->val, maxV); 

        if(left && right && minV < root->val && maxV > root->val){
            return true;
        }else{
            return false; 
        }
    }

    bool isValidBST(TreeNode* root) {
        return helper(root);
    }
};