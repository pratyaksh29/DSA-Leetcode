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
    TreeNode* solve(vector<int>&inorder, vector<int>& postorder, int inorderstart, int inorderend, int& postorderindex,unordered_map<int,int>&mp){
        if(inorderend<inorderstart || postorderindex<0){
            return NULL;
        }
        int root = postorder[postorderindex--];
        TreeNode* node = new TreeNode(root);
        int pos = mp[root];
        node->right = solve(inorder,postorder,pos+1,inorderend,postorderindex,mp);
        node->left = solve(inorder,postorder,inorderstart,pos-1,postorderindex,mp);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderindex =postorder.size()-1;
        unordered_map<int,int>mp;
        for(int i =0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return solve(inorder,postorder,0,inorder.size()-1,postorderindex,mp);
    }
};