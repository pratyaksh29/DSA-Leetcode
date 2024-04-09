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
    vector<int>ans;
    void dfs(TreeNode* root){
        if(root==NULL){
            return;
        }
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        int n = ans.size();
        if(n==1){
            return false;
        }
        int left = 0;
        int right = n-1;
        while(left<right){
            int sum = ans[left] + ans[right];
            if(sum==k){
                return true;
            }
            else if (sum<k){
                left++;
            }
            else{
                right--;
            }
        }
        return false;
        
    }
};