 
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
