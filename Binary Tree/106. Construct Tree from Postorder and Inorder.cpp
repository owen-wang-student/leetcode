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

    TreeNode* helper(vector<int> inorder, vector<int> postorder, int ins, int ine, int posts, int poste){
        if(ins > ine || posts > poste){
            return NULL;
        }

        int data = postorder[poste];
        int inOrderDataIndex = - 1; 

        for(int i = ins; i <= ine; i++){
            if(inorder[i] == data){
                inOrderDataIndex = i;
            }
        }

        int lins = ins; 
        int line = inOrderDataIndex - 1; 
        int lposts = posts; 
        int lposte = posts + line - lins; 

        int rins = inOrderDataIndex + 1; 
        int rine = ine; 
        int rposts = lposte + 1; 
        int rposte = poste - 1; 

        TreeNode* root = new TreeNode(data); 
        root->left = helper(inorder, postorder, lins, line, lposts, lposte);
        root->right = helper(inorder, postorder, rins, rine, rposts, rposte);
        return root; 
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return helper(inorder, postorder, 0, n-1, 0, n-1);
    }
};