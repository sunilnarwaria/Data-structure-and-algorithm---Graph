// using BFS method


  bool solve(vector<vector<int>>& graph,vector<int>& col,int v,vector<bool>& vis)
    {
        queue<int> q;
        q.push(v);
        col[v] = 1;
        vis[v] = true;
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            vis[t] = true;
            for(auto x : graph[t])
            {
                vis[x] = true;
                if(t == x)
                    return false;
                if(col[x] == -1)
                {
                    col[x] = 1-col[t];
                    q.push(x);
                }
                else if(col[x] == col[t])
                    return false;
            }
        }
        return true;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        
         int n = graph.size();
         vector<int> col(n,-1);
         vector<bool> vis(n,false);
         bool ans = true;
         for(int i=0;i<n;i++)
         {
            if(!vis[i])
            {
                ans = ans & solve(graph,col,i,vis);
            }
         }
      
      // using DFS method
      
      
       bool dfs(vector<vector<int>> & graph,vector<int> &color,int u)
    {
        for(auto v:graph[u])
        {
            if(color[v]==-1)
            {
                color[v]=1-color[u];
                if(!dfs(graph,color,v)) return false;
            }
            else if(color[v]==color[u]) return false;
        }
	    return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> color(V,-1);
	    for(int i=0;i<V;i++)
	        if(color[i]==-1) 
	        {
	            color[i]=1;
	            if(!dfs(graph,color,i))
	            return false;
	        }
	    return true;
    }
