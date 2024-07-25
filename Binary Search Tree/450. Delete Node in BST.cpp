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
    int getSucessor(TreeNode* root){
        if(!root->left){
            return root->val;
        }
        return getSucessor(root->left);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return root; 
        }
        if(root->val == key){
            if(root->right && root->left){
                cout << root->val;
                int s = getSucessor(root->right);
                root->val = s;
                root->right = deleteNode(root->right, s);
            }else if(root->right){
                return root->right;
            }else if(root->left){
                return root->left; 
            }else{
                return NULL; 
            }
        }

        if(root->val < key){
           root->right = deleteNode(root->right, key);
        }else{
           root->left = deleteNode(root->left, key);
        }
        return root; 
    }
};