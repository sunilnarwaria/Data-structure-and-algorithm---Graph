 
 // Method 1  using dfs, one another method is *union-find*
 
       int dfs(int i,int j,vector<vector<char>>& grid)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]=='0')return 0;
        grid[i][j]='0';
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
        return 1;
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        
         if(grid.size()==0)return 0;
        int count=0;
       for(int i=0;i<grid.size();i++)
       {
           for(int j=0;j<grid[i].size();j++)
           {
               if(grid[i][j]=='1')
               {
                   count+=dfs(i,j,grid);
               }
           }
       }
        return count;
        
    }


//Method 2

 int total;
   
    void Union(vector<int> &ranks_, vector<int> &parents_, int u, int v){
        int pu = Find(parents_, u);
        int pv = Find(parents_, v);
        
        if(pu == pv) return;
        if(ranks_[pu] < ranks_[pv]) parents_[pu] = pv;
        else if(ranks_[pv] < ranks_[pu]) parents_[pv] = pu;
        else if(ranks_[pv] == ranks_[pu]){
            parents_[pv] = pu;
            ranks_[pu] += 1;
        }
        --total;
    }
    
    int Find(vector<int> &parents_, int u){
        if(u != parents_[u]){
            parents_[u] = Find(parents_, parents_[u]);
        }
        return parents_[u];
    }


    int numIslands(vector<vector<char>>& grid) {
        
        if(grid.size() == 0||grid[0].size() == 0) return 0;
        int row = grid.size();
        int col = grid[0].size();
        
        
        
        vector<int> parents_(row*col, 0);
        vector<int> ranks_(row*col, 0);
        
        for(int i = 0; i<parents_.size(); ++i){
            parents_[i] = i;
          }
        
        total = row*col;
        
        for(int i =0; i < row ; i++){
            for(int j=0; j < col; j++){
                int id = i*col + j;
                
                if(grid[i][j] == '0') --total;
                else{
                 
                    if(i-1 >= 0 && grid[i-1][j] == '1') Union(ranks_, parents_, id, (i-1)*col + j);
                    if(j-1 >= 0 && grid[i][j-1] == '1') Union(ranks_, parents_, id, i*col + j-1);
                }

  

             }
         }
        return total;
        
    }
