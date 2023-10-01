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
    vector<int> ans;
    unordered_map<TreeNode*, TreeNode*> childToParent;

    void buildChildToParent(TreeNode* root) {
        if (!root) return;
        if (root->left) {
            childToParent[root->left] = root;
            buildChildToParent(root->left);
        }
        if (root->right) {
            childToParent[root->right] = root;
            buildChildToParent(root->right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root || k < 0) return {};

        buildChildToParent(root);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        while (!q.empty() && k > 0) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && visited.find(node->left) == visited.end()) {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right && visited.find(node->right) == visited.end()) {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if (childToParent[node] && visited.find(childToParent[node]) == visited.end()) {
                    q.push(childToParent[node]);
                    visited.insert(childToParent[node]);
                }
            }
            k--;
        }

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};
