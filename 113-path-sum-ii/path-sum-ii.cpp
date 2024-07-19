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
    vector<vector<int>>ans;
    
public:
    void solve (TreeNode* root, int targetSum,vector<int>depth){
        if(root==NULL){
            return;
        }
        depth.push_back(root->val);
        if(!root->left && !root->right && targetSum == root->val){
            ans.push_back(depth);
        }
        solve(root->right,targetSum-(root->val),depth);
        solve(root->left,targetSum-(root->val),depth);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>depth;
        solve(root,targetSum,depth);
        return ans;

    }
};