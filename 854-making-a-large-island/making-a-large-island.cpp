class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet s(n*n);
        // step 1 of connecting components is done, iss hum left right vale  
        // jo bhi components h unka size determine kr skte h
         int flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    flag=1;
                }
            }
        }
        if(flag==0)
        {
            return n*n;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    continue;
                }

                int dx[]={-1,0,1,0};
                int dy[] ={0,1,0,-1};
                for(int k=0;k<4;k++)
                {
                    int newr = i + dx[k];
                    int newc = j + dy[k];
                    if(newr>=0 and newr<n and newc>=0 and newc<n and grid[newr][newc]==1)
                    {
                       s.unionBySize(i*n + j,newr*n + newc);
                    }
                }
            }
        }

        // step-2 of converting every 0 to 1 and checkng if we
        // get a component of complete size of not
         int mx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    continue;
                }
                int dx[]={-1,0,1,0};
                int dy[] ={0,1,0,-1};
                set<int>components;
                for(int k=0;k<4;k++)
                {
                    int newr = i + dx[k];
                    int newc = j + dy[k];
                     if(newr>=0 and newr<n and newc>=0 and newc<n and grid[newr][newc]==1)
                     {
                        components.insert(s.findUPar(newr*n + newc));
                     }
                }

                int sizetotal=0;
                for(auto it : components)
                {
                    sizetotal += s.size[it]; 
                }
                mx = max(mx,sizetotal+1);

            }
        }

return mx;
        
    }
};