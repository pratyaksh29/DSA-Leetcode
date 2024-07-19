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
    int sumNumbers(TreeNode* root) {
        int sum =0;
        stack<pair<TreeNode*,int>>st;
        st.push({root,0});
        while(!st.empty()){
            auto [node,cur] = st.top();
            st.pop();
            cur=cur*10 + node->val;
            if(!node->right && !node->left){
                sum+=cur;
            }
            if(node->right){
                st.push({node->right,cur});
            }
            if(node->left){
                st.push({node->left,cur});
            }
        }
        return sum;
    }
};