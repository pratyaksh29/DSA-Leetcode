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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int maxwidth =1;
        queue<pair<TreeNode*,int>>q; //node and it's associated index number
        // we will assign each level with an index number in ascending order

        q.push({root,0});

        while(q.empty()==false){
            int size = q.size();
            int startindex = q.front().second; 
            int endindex = q.back().second; 

            maxwidth = max(maxwidth, endindex-startindex+1);

            for(int i =0;i<size;i++){
                auto curr_pair = q.front();
                TreeNode* node = curr_pair.first;
                int nodeindex = curr_pair.second - startindex; //stuck here
                //do this to reset the nodes back to 0,1,2,etc to assign their children
                q.pop();

                if(node->left){
                    q.push({node->left,2LL*nodeindex + 1});

                }
                if(node->right){
                    q.push({node->right,2L*nodeindex + 2});

                }

            }


        } 
        return maxwidth;
    }
};