class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,0);//0 means uncolored

        for(int i =0;i<n;i++){
            if(color[i]!=0){
                continue;
            }
            color[i]=1;
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                auto node = q.front();
                q.pop();
                for(auto it : graph[node]){
                    if(color[it]==0){
                        color[it]= -color[node];
                        q.push(it);
                    }
                    else if (color[it]==color[node]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};