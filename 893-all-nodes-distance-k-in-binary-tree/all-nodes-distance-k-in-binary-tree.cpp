class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (root == NULL) {
            return {};
        }

        // Map each node to its parent
        unordered_map<TreeNode*, TreeNode*> parentMap;
        mapParents(root, nullptr, parentMap);

        // Perform BFS from the target node
        queue<pair<TreeNode*, int>> q;
        unordered_set<TreeNode*> visited;
        q.push({target, 0});
        visited.insert(target);

        vector<int> ans;

        while (!q.empty()) {
            auto [node, distance] = q.front();
            q.pop();

            if (distance == k) {
                ans.push_back(node->val);
            }

            // Check the left child
            if (node->left && visited.find(node->left) == visited.end()) {
                q.push({node->left, distance + 1});
                visited.insert(node->left);
            }

            // Check the right child
            if (node->right && visited.find(node->right) == visited.end()) {
                q.push({node->right, distance + 1});
                visited.insert(node->right);
            }

            // Check the parent
            if (parentMap[node] && visited.find(parentMap[node]) == visited.end()) {
                q.push({parentMap[node], distance + 1});
                visited.insert(parentMap[node]);
            }
        }

        return ans;
    }

private:
    void mapParents(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        if (node != nullptr) {
            parentMap[node] = parent;
            mapParents(node->left, node, parentMap);
            mapParents(node->right, node, parentMap);
        }
    }
};
