class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>, //diff, row/col
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        vector<int>dir = {-1,0,1,0,-1};
        while(!pq.empty()){
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row==n-1 && col == m-1){
                return diff;
            }
            for(int i =0;i<4;i++){
                int nrow = row + dir[i];
                int ncol = col + dir[i+1];
                if(nrow>=0 && ncol >=0 && nrow <n && ncol<m){
                    int neweffort = max(diff,abs(heights[row][col]-heights[nrow][ncol]));
                    if(neweffort<dist[nrow][ncol]){
                        dist[nrow][ncol] = neweffort;
                        pq.push({neweffort,{nrow,ncol}});
                    }
                }
            }
            
        }   
        return 0;


    }
};