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
    void dfs(vector<string>& paths, string ans, TreeNode* root){
        ans += to_string(root->val);
        ans += "->";
        cout << ans << endl;
        if(!root->left && !root->right){
            ans = ans.substr(0, ans.length() - 2); 
            paths.push_back(ans); 
            ans = ans.substr(0, ans.length() - 1); 
        }
        if(root->left) dfs(paths, ans, root->left);
        if(root->right) dfs(paths, ans, root->right);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths; 
        dfs(paths, "", root);
        return paths; 
    }
};