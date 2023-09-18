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
    void findposition(vector<int> inorder, int root, unordered_map<int, int>& nodetoindex) {
        for (int i = 0; i < inorder.size(); i++) {
            nodetoindex[inorder[i]] = i;
        }
    }
    
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int& postorderindex, int inorderstart, int inorderend, unordered_map<int, int>& nodetoindex) {
        if (postorder.size() < postorderindex || inorderend < inorderstart) {
            return NULL;
        }
        
        int root = postorder[postorderindex--];
        TreeNode* node = new TreeNode(root);
        
        findposition(inorder, root, nodetoindex);
        int position = nodetoindex[root];
        
        node->right = solve(inorder, postorder, postorderindex, position+1, inorderend, nodetoindex); 
        //got stuck here ; node->right will come before node->left
        node->left = solve(inorder, postorder, postorderindex, inorderstart, position - 1, nodetoindex);
       
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderindex = postorder.size()-1;
        unordered_map<int, int> nodetoindex;
        TreeNode* ans = solve(inorder, postorder, postorderindex, 0, postorder.size() - 1, nodetoindex);
        return ans;
    }
};

