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
    TreeNode* solve(vector<int>& preorder,vector<int>& inorder,int inorderstart,int inorderend,int &preorderstart,unordered_map<int,int>&mp){
        if(preorderstart>preorder.size() || inorderend<inorderstart){
            return NULL;
        }
        int root = preorder[preorderstart++];
        TreeNode* node = new TreeNode(root);
        int pos = mp[root];
        node->left = solve(preorder,inorder,inorderstart,pos-1,preorderstart,mp);
        node->right = solve(preorder,inorder,pos+1,inorderend,preorderstart,mp);
        return node;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        int preorderstart=0;
        return solve(preorder,inorder,0,inorder.size()-1,preorderstart,mp);
        
    }
};