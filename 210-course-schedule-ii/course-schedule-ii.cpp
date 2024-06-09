class Solution {
public:
    bool detectCycle(int node, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj, stack<int>& st) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (int it : adj[node]) {
            if (!vis[it]) {
                if (detectCycle(it, vis, pathVis, adj, st)) {
                    return true;
                }
            } else if (pathVis[it] == 1) {
                return true;
            }
        }

        pathVis[node] = 0;
        st.push(node); // Push node to stack after visiting all its adjacent nodes
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        vector<vector<int>> adj(v);
        for (auto& it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(v, 0);
        vector<int> pathVis(v, 0);
        stack<int> st;

        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                if (detectCycle(i, vis, pathVis, adj, st)) {
                    return {}; // Return empty vector if a cycle is detected
                }
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
