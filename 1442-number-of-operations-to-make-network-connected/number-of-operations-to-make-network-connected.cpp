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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n>connections.size()+1){
            return -1;
        }
        int V = connections.size();
        DisjointSet ds(V);
        //need to find the number of connected components
        int extraedges = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            ds.unionBySize(u,v);
        }
        int c = 0;
        for(int i =0;i<n;i++){
            if(ds.findUPar(i)==i){
                c++;
            }
        }


        return c-1;
    }
};