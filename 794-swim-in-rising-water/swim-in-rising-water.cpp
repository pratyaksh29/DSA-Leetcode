class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        auto compare = [&grid](const pair<int, int>& a, const pair<int, int>& b) {
            return grid[a.first][a.second] > grid[b.first][b.second]; 
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
        int n = grid.size();
        pq.push({n-1,n-1});
        int maxi = grid[n-1][n-1];
        vector<vector<int>> vis(n, vector<int>(n, 0));
        while(!pq.empty()){
            auto i = pq.top().first;
            auto j = pq.top().second;
            maxi = max(maxi,grid[i][j]);
            if(i==0 && j ==0){
                break;
            }
            pq.pop();
            if(i-1>=0&&vis[i-1][j]!=1){
                pq.push({i-1,j});
                vis[i-1][j]=1;
            }
            if(j-1>=0&&vis[i][j-1]!=1){
                pq.push({i,j-1});
                vis[i][j-1]=1;
            }
            if(j+1<n && vis[i][j+1]!=1){
                pq.push({i,j+1});
                vis[i][j+1]=1;
            }
            if(i+1<n && vis[i+1][j]!=1){
                pq.push({i+1,j});
                vis[i+1][j]=1;
            }
        }
        return maxi;
    }
};