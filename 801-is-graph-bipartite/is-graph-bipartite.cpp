class Solution {
public:
    bool dfs(int a , int currcol , vector<vector<int>>& graph,vector<int>& color){
        color[a] = !currcol;
        for(auto it : graph[a]){
            if(color[it]==-1){
                if(dfs(it,!currcol,graph,color)==false){
                    return false;
                }
            }
            else if(color[a] == color[it]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i =0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0,graph,color)==false){
                    return false;
                }
            }
        }
        return true;

    }
};