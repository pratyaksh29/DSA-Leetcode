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
    // Return the Kth smallest element in the given BST
    void inorder(TreeNode* root,int K, int &count,int &ans){
        if(root==0) return ;
        inorder(root->left,K,count,ans);
        count++;
        if(count==K) {
            ans=root->val;
            return ;
        } 
        inorder(root->right,K,count,ans);
    }
    int kthSmallest(TreeNode *root, int K) {
       int count=0;
       int ans;
       inorder(root,K,count,ans);
       if(count<K) return -1;
       return ans;
    }
};