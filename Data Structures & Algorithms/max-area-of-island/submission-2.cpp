class Solution {
private:
    void dfs(vector<vector<int>>& grid, int r, int c, int& currArea){
        if(r < 0 || r >= grid.size())    return;
        if(c < 0 || c >= grid[0].size()) return;
        if(grid[r][c] == 0)              return;

        currArea += 1;
        grid[r][c] = 0;
        dfs(grid, r-1, c, currArea);
        dfs(grid, r+1, c, currArea);
        dfs(grid, r, c-1, currArea);
        dfs(grid, r, c+1, currArea);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();

        int maxArea = 0;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 1){
                    int currArea = 0;
                    dfs(grid, r, c, currArea);
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        return maxArea;
    }
};
