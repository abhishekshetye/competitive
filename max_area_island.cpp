class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int ans = 0;
        
        for (int i = 0; i < grid.size(); ++i) 
            for (int j = 0; j < grid[0].size(); ++j) 
                if (grid[i][j] == 1)
                    ans = max(ans, dfs(i, j, grid));
            
        
        return ans;
        
    }
    
    int dfs(int i, int j, vector<vector<int>> &grid) {
        
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1)
            return 0;
        
        grid[i][j] = 2;
        
        int sum = 1;
        
        sum += dfs(i, j - 1, grid);
        sum += dfs(i, j + 1, grid);
        sum += dfs(i - 1, j, grid);
        sum += dfs(i + 1, j, grid);
        
        return sum;
        
    }
};