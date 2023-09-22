/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool getpath(TreeNode* root,vector<TreeNode*>&path,TreeNode* p){
        if(!root){
            return false;
        }
        path.push_back(root);
        if(root->val == p->val){
            return true;
        }
        if(getpath(root->left,path,p)){
            return true;
        }
        if(getpath(root->right,path,p)){
            return true;
        }
        path.pop_back();
        return false;

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }
        vector<TreeNode*>pathp,pathq;

        if (!getpath(root, pathp, p) || !getpath(root, pathq, q)) {
            return NULL; // One or both nodes not found in the tree
        }

        int index;
        int minvector = min(pathp.size(),pathq.size());
        for(index = 0;index < minvector;index++){
            if(pathp[index]->val!=pathq[index]->val){
                break;
            }
        }
        return pathp[index-1];
        
    }
};
