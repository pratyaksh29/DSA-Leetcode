class Solution {
public:
    bool detectcycle(int node,vector<int>&vis,vector<int>&pathvis,vector<vector<int>>& adj){
        vis[node]=1;
        pathvis[node]=1;
        for(int it :adj[node]){
            if(!vis[it]){
                if(detectcycle(it,vis,pathvis,adj)==true){
                    return true;
                }
            }
            else if(pathvis[it]==1){
                return true;
            }
        }
        pathvis[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        vector<vector<int>>adj(v);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(v,0);
        vector<int>pathvis(v,0);
        for(int i =0;i<v;i++){
            if(!vis[i]){
                if(detectcycle(i,vis,pathvis,adj)==true){
                    return false;
                }
            }
        }
        return true;


    }
};