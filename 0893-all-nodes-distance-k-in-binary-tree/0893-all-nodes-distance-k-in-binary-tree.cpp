class Solution {
public:
    vector<int> ans;
    unordered_map<TreeNode*, TreeNode*> childToParent;
    unordered_set<TreeNode*> visited;

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Build the child to parent mapping
        buildChildToParent(root);

        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);

        int currentLevel = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            if (currentLevel == k) {
                while (!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }

            for (int i = 0; i < levelSize; ++i) {
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
                TreeNode* parent = childToParent[node];
                if (parent && visited.find(parent) == visited.end()) {
                    q.push(parent);
                    visited.insert(parent);
                }
            }
            currentLevel++;
        }

        return ans;
    }

    void buildChildToParent(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        childToParent[root] = nullptr;

        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();

            if (node->left) {
                s.push(node->left);
                childToParent[node->left] = node;
            }
            if (node->right) {
                s.push(node->right);
                childToParent[node->right] = node;
            }
        }
    }
};
