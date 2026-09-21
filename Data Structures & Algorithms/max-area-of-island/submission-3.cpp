class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<pair<int, int>> directions = { {-1,0},{1,0},{0,-1},{0,1} };

        int maxArea = 0;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 1){
                    int currArea = 1;
                    grid[r][c] = 0;

                    queue<pair<int, int>> neighbors;
                    neighbors.push({r, c});

                    while(!neighbors.empty()){
                        pair<int, int> coord = neighbors.front(); neighbors.pop();
                        int cr = coord.first, cc = coord.second;
                        for(pair<int, int> dir : directions) {
                            int nr = cr + dir.first, nc = cc + dir.second;
                            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1){
                                currArea += 1;
                                grid[nr][nc] = 0;
                                neighbors.push({nr,nc});
                            }
                        }
                    }

                    maxArea = max(maxArea, currArea);
                }
            }
        }

        return maxArea;
    }
};
