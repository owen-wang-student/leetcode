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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q; 
        
        int maxSum = INT_MIN; 
        int levelSum; 
        int maxLevel = 0;
        int curLevel = 0;
        
        if(root) {
            q.push(root);
        }else{
            return 0; 
        }

        while(!q.empty()){
            curLevel += 1; 
            levelSum = 0; 
            cout << "Level:" << curLevel << endl;
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* current = q.front();
                cout << current->val << endl; 
                q.pop();
                if(current->right) q.push(current->right);
                if(current->left) q.push(current->left);
                levelSum += current->val; 
            }
            if(levelSum > maxSum){
                maxSum = levelSum; 
                maxLevel = curLevel; 
            }
        }
    return maxLevel; 
    }
};