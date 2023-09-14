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
    int length(TreeNode* root){
        if(root==NULL)
        {
            return NULL;
        }
        int left = length(root->left);
        int right = length(root->right);

        if(left==-1 || right==-1){
          return -1;
        }

        if(abs(left-right)>1){
          return -1;
        }

        return max(left,right)+1;


    }

    bool isBalanced(TreeNode* root) {
      int c = length(root);
      if(c==-1){
        return false;
      }
      return true;


        
    }
};