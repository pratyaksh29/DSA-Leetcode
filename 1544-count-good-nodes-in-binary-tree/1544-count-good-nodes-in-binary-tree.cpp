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
    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        stack<pair<TreeNode*,int>>st; //create a pair in a stack to store the node and the max value till that node
        st.push({root,root->val});
        int goodnodes = 0;

        while(st.empty()==false){
            auto [node,maxval] = st.top();
            st.pop();
            if(node->val>=maxval){ //if
                goodnodes++;
                maxval = max(maxval,node->val);
            }
            if(node->left){
                st.push({node->left,maxval});
            }
            if(node->right){
                st.push({node->right,maxval});
            }
        }
        return goodnodes;
    }
};