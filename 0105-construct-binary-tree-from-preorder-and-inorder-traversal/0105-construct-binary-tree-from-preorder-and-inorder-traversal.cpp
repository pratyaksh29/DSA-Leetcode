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
    int findposition (vector<int> inorder, int root){
        for(int i =0;i<inorder.size();i++){
            if(root == inorder[i]){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &preorderindex,int inorderstart,int inorderend){
        if(preorder.size()<preorderindex || inorderend<inorderstart){
            return NULL;
        }
        int root= preorder[preorderindex++];
        TreeNode* node = new TreeNode(root);
        int position = findposition(inorder,root);
        node->left = solve(preorder,inorder,preorderindex,inorderstart,position-1);
        node->right = solve(preorder,inorder,preorderindex,position+1,inorderend);
        return node;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderindex =0;
        TreeNode* ans = solve(preorder,inorder,preorderindex,0,preorder.size()-1);
        return ans;
        
    }
};