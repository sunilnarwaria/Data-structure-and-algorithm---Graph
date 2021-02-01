
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
