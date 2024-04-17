class DisjointSet{ //union by size
	vector<int>size,parent;
public:
	DisjointSet(int n){ //constructor
		size.resize(n+1); //n+1 if 1 based graph
		parent.resize(n+1);
		for(int i =0;i<=n;i++){
			parent[i]=i;
			size[i]=1;
		}
	}
	int findUPar(int node){
		if(node==parent[node]){
			return node;
		}
		return parent[node]=findUPar(parent[node]);
	}

	void unionBySize(int u,int v){
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		if(ulp_u==ulp_v) return; //belonging to same component
		if(size[ulp_u]<size[ulp_v]){
			parent[ulp_u]=ulp_v;
			size[ulp_v]+=size[ulp_u];
		}
		else{
			parent[ulp_v]=ulp_u;
			size[ulp_u]+=size[ulp_v];
		}
	}
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow = 0;
        int maxcol =0;
        for(auto it : stones){
            maxrow = max(maxrow, it[0]);
            maxcol = max(maxcol,it[1]);
            
        }
        DisjointSet ds(maxrow + maxcol+1);
        unordered_map<int,int>uniquenodes;
        for(auto it : stones){
            int noderow = it[0];
            int nodecol = it[1] + maxrow + 1;
            ds.unionBySize(noderow,nodecol);
            uniquenodes[noderow]=1;
            uniquenodes[nodecol]=1;
        }
        int cnt = 0;
        for(auto it : uniquenodes){
            if(ds.findUPar(it.first)==it.first){
                cnt++;
            }
        }
        return stones.size() - cnt;
    }
};