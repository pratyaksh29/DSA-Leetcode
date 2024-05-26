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
    int dfs(TreeNode* root, int cur){
        if(!root){
            return 0;
        }
        cur = cur*10 + root->val; //keep moving the number by tens place
        if(!root->left && !root->right){
            return cur; //if no next node; return the current sum
        }
        return dfs(root->left,cur) + dfs(root->right,cur); //add all the numbers
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root,0); //start with 0
    }
};

