

  class Solution {
public:
    vector<vector<int>> g,bridges;
    vector<int> vis,low,id; 
    int cnt=0;
    void dfs(int node,int par) {
        vis[node]=1;
        low[node]=id[node]=cnt++;
        for(int nei: g[node]){
            if(!vis[nei]){
                dfs(nei,node);
                low[node]=min(low[node],low[nei]); 
                if(id[node]<low[nei]){  
                    bridges.push_back({node,nei});
                }
            }else if(nei != par){   
                low[node]=min(low[node],id[nei]);  
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        
        
        
        g=vector<vector<int>>(n,vector<int>());
       
        for(auto x: edges){ 
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        vis=vector<int>(n,0);   
        low=vector<int>(n,0);   
        id=vector<int>(n,0);   
        
        
        dfs(0,-1);
        return bridges;
    }
};
