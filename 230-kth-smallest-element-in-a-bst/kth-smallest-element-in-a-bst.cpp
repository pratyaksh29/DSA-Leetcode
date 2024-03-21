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
class Solution { //better approach
public:
    void inorder(TreeNode* root,int &k,int &c,int &ans){
        if(root == NULL){
            return;
        }
        inorder(root->left,k,c,ans);
        c++;
        if(c==k){
            ans=root->val;
            return;
        }
        inorder(root->right,k,c,ans);
    }
    int kthSmallest(TreeNode* root, int k) {    
        if(root == NULL){
            return NULL;
        }
        int c = 0;
        int ans;
        inorder(root,k,c,ans);

        return ans;
    }
};

