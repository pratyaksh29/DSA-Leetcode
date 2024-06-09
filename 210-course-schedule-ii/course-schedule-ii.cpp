class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        vector<vector<int>>adj(v);
        for(auto i : prerequisites){
            adj[i[1]].push_back(i[0]);
        }

        vector<int>indegree(v,0);
        for(int i=0;i<v;i++){
            for(int it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i =0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        if(ans.size()!=v){
            return {};
        }
        return ans;
    }
};