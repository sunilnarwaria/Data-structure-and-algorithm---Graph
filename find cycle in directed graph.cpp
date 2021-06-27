
bool find_cycle(vector<vector<int>> &graph,int n,int s,vector<int> &visited,int par)
{
    visited[s] = 1;
    
    for (int i = 0;i < graph[s].size();i++)
    {
        if (visited[graph[s][i]] == 0)
        {
            if (find_cycle(graph,n,graph[s][i],visited,s) == true)
                return true;
        } else 
        {
            if (graph[s][i] != par)
                return true;
        }
    }
    
    return false;
}

int Solution::solve(int n, vector<vector<int> > &a) {
    
    int m = a.size();
    
    if (m >= n)
        return 1;
    
    vector<vector<int>> graph;
    graph.resize(n+1);
    
    for (int i = 0;i < m;i++)
    {
        graph[a[i][0]].emplace_back(a[i][1]);
        graph[a[i][1]].emplace_back(a[i][0]);
    }
    
    vector<int> visited;
    visited.resize(n+1,0);
    
    for (int i = 1;i <= n;i++)
    {
        if (visited[i] == 0)
        {
            if (find_cycle(graph,n,i,visited,0) == true)
                return 1;
        }
    }
    
    return 0;
}
