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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int>depth;
        findPaths(root,targetSum,ans,depth);
        return ans;
        

    }

    void findPaths(TreeNode* root, int targetSum,vector<vector<int>>& ans,vector<int>depth){
        if (root == NULL) {
            return;
        }
        depth.push_back(root->val);
        if(!root->left && !root->right && targetSum==root->val){
            ans.push_back(depth);
        }
        findPaths(root->left,targetSum-root->val,ans,depth);
        findPaths(root->right,targetSum-root->val,ans,depth);

    }
};

