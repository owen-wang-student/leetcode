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

    TreeNode* helper(vector<int> preorder, vector<int> inorder, int inS, int inE, int preS, int preE){
        if(inS > inE || preS > preE){
            return NULL;
        }

        int data = preorder[preS];
        int index = -1; 
        for(int i = inS; i <= inE; i++){
            if(inorder[i] == data){
                index = i; 
            }
        }

        int leftInStart = inS;
        int leftInEnd = index - 1;
        int leftPreStart = preS + 1;
        int leftPreEnd = leftPreStart + leftInEnd - leftInStart;

        int rightInStart = index + 1;
        int rightInEnd = inE;
        int rightPreStart = leftPreEnd + 1;
        int rightPreEnd = preE;

        TreeNode* root = new TreeNode(data);
        root->left = helper(preorder, inorder, leftInStart, leftInEnd, leftPreStart, leftPreEnd);
        root->right = helper(preorder, inorder, rightInStart, rightInEnd, rightPreStart, rightPreEnd);
        
        return root; 
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return helper(preorder, inorder, 0, n-1, 0, n-1);
    }
};