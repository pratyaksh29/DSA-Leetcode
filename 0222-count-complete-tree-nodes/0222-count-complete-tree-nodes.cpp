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
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int l = leftheight(root);
        int r = rightheight(root);
        if(l==r){
            return (1<<l)-1; //calculate ()height's power of 2) -1
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int leftheight(TreeNode* root){
        int c =0;
        while(root){
            root=root->left;
            c++;
        }
        return c;
    }

    int rightheight(TreeNode* root){
        int c =0;
        while(root){
            root=root->right;
            c++;
        }
        return c;
    }
    
};