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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        stack<TreeNode*>st;

        st.push(root);
        int c = 0;
        while(st.empty()==false){
            TreeNode* node = st.top();
            st.pop();

            if(!node->right && !node->left){
                if(node->val==targetSum){
                    return true;
                }
            }

            if(node->right){
                st.push(node->right);
                node->right->val += node->val; //got stuck here
            }

            if(node->left){
                st.push(node->left);
                node->left->val += node->val; //got stuck here
            }

            
            
        }
        return false;


        
    }
};