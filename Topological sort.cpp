 
 //In DFS, we print a vertex and then recursively call DFS for its adjacent vertices. In topological sorting, we need to print a vertex before its adjacent vertices. 
  // *** in topological sorting atleast one vertex should have 0 degree
// 210. course schedule II Leetcode
   
      bool isCyclic(int v, vector<int> &ans, vector<int> &vis, vector<vector<int>> &adj){
        vis[v]=-1;
        for(int u: adj[v]){
            if(vis[u]==-1)
                return true;
            if(vis[u]==0 && isCyclic(u, ans, vis, adj))
                return true;
        }
        vis[v]=1;
        ans.push_back(v);
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)     {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++)
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        vector<int> vis(numCourses,0);
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(isCyclic(i, ans, vis, adj))
                    return {};
            }
        }
        return ans;
     }


 // Kanhs algo for topological sorting
   
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        queue<int> nodes;
        vector<int> indegrees(numCourses, 0);
        int visit_node_size = 0;
        vector<int> result;
        
        for (auto item : prerequisites) {
            graph[item.second].push_back(item.first);
            ++ indegrees[item.first];
        }
        for (int node_id = 0; node_id < indegrees.size(); ++ node_id) {
            if (indegrees[node_id] == 0) {
                nodes.push(node_id);
            }
        }
        while (!nodes.empty()) {
            ++ visit_node_size;
            int node_id = nodes.front();
            nodes.pop();
            result.push_back(node_id);
            for (auto neighber_id : graph[node_id]) {
                -- indegrees[neighber_id];
                if (indegrees[neighber_id] == 0) {
                    nodes.push(neighber_id);
                }
            }
        }
        
        return visit_node_size == numCourses ? result : vector<int>();
    }
