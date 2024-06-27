class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n]; // from,to,price
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;//stops,node,weighted distance
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        dist[src]=0;

        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int price = q.front().second.second;
            q.pop();
            if(stops>k){
                continue;
            }
            for(auto it : adj[node]){
                int adjnode = it.first;
                int adjwt = it.second;
                if(dist[node]+adjwt<dist[adjnode]){ //remember this
                    dist[adjnode]=price+adjwt;
                    q.push({stops+1,{adjnode,dist[adjnode]}});
                }
            }
        }
        if(dist[dst]==1e9){
            return -1;
        }
        else{
            return dist[dst];
        }




    }
};