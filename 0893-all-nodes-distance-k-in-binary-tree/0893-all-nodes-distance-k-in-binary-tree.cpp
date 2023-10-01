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
    vector<int>ans;
    unordered_map<TreeNode* ,TreeNode*>childtoparent; //child,parent
    unordered_set<TreeNode*> visited;

    void findParent(TreeNode* node){
        if(!node) return;
        if(node->left){
            childtoparent[node->left]=node;
            findParent(node->left);
        }
        if(node->right){
            childtoparent[node->right]=node;
            findParent(node->right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root){
            return {};
        }
        findParent(root);
        dfs(target,k);
        return ans;
    }

    void dfs(TreeNode* target, int k){
        if(visited.find(target)!=visited.end()){
            return;
        }
        visited.insert(target);
        if(k==0){
            ans.push_back(target->val);
            return;
        }
        if(target->left){
            dfs(target->left,k-1);
        }
        if(target->right){
            dfs(target->right,k-1);
        }
        TreeNode* p = childtoparent[target];
        if(p){
            dfs(p,k-1);
        }


    }
};