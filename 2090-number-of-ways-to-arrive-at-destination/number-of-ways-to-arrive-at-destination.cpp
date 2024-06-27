class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>>adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]}); //u,v,time
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,long long>,
        vector<pair<long long,long long>>,
        greater<pair<long long,long long>>>pq; //pq -> distance , node

        vector<long long>dist(n,1e18);
        dist[0]=0; //
        vector<long long>count(n,0);
        count[0]=1;

        pq.push({0,0});
        
        while(!pq.empty()){
            long long newdist = pq.top().first;
            long long newnode = pq.top().second;
            pq.pop();
            if(newdist>dist[newnode]){
                continue;
            }
            for(auto it : adj[newnode]){
                long long v = it.first;
                long long time = it.second;
                if(dist[newnode]+time < dist[v]){
                    dist[v]=dist[newnode]+time;
                    pq.push({dist[v],v});
                    count[v] = count[newnode];
                }
                else if(dist[newnode]+time== dist[v]){
                    count[v] = (count[v] + count[newnode]) % 1000000007;
                    
                }
            }
        }
        return count[n-1] % 1000000007;

        


        


    }
};