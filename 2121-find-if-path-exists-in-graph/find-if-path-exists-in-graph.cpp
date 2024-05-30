class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>graph(n); // initialise graph with n nodes
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]); //twice since its bidirectional
            graph[edge[1]].push_back(edge[0]);
        }
        queue<int>q;
        q.push(source);
        vector<int>visited(n,0);
        visited[source]=1;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node==destination){
                return true;
            }
            for(int adjacent : graph[node]){
                if(visited[adjacent]==0){
                    visited[adjacent]=1;
                    q.push(adjacent);
                }
            }
        }
        return false;
    }
};