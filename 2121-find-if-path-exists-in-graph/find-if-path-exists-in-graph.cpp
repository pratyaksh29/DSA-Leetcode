class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>graph(n);
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        stack<int>st;
        st.push(source);
        vector<int>visited(n,0);
        visited[source]=1;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(node == destination){
                return true;
            }
            for(auto adj : graph[node]){
                if(!visited[adj])
                    st.push(adj);
                    visited[adj]=1;
            }
        }
        return false;

    }
};