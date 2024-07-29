
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
    void dfs(TreeNode* root,int &diff,int &prevval){
        if(root==NULL){
            return;
        }
        dfs(root->left,diff,prevval);
        if(prevval!=-1){
            diff = min (diff , abs(root->val-prevval));
        }
        prevval = root->val;
        dfs(root->right,diff,prevval);

        
    }
    int minDiffInBST(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int prevval = -1;
        int diff = INT_MAX;
        dfs(root,diff,prevval);
        return diff;

    }
};