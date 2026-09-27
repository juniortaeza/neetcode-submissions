class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> treasures;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 0)
                    treasures.push({r, c});
            }
        }

        vector<pair<int, int>> directions = { {-1,0},{1,0},{0,-1},{0,1} };
        while(!treasures.empty()){
            int levelSize = treasures.size();
            for(int i = 0; i < levelSize; i++){
                pair<int, int> coord = treasures.front(); treasures.pop();
                int cr = coord.first, cc = coord.second;
                for(pair<int, int> & dir : directions){
                    int nr = cr + dir.first, nc = cc + dir.second;
                    if(nr < rows && nr >= 0 && nc < cols && nc >= 0 && grid[nr][nc] == INT_MAX){
                        grid[nr][nc] = 1 + grid[cr][cc];
                        treasures.push({nr, nc});
                    }
                }
            }
        }
    }
};
