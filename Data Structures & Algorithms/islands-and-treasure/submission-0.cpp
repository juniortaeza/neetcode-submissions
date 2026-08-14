class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if(grid.empty()) return;
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 0){
                    q.push({r,c});
                }
            }
        }

        vector<pair<int,int>> directions = { {-1,0},{1,0},{0,-1},{0,1} };
        while(!q.empty()){
            pair<int,int> rcPair = q.front(); q.pop();
            int cr = rcPair.first;
            int cc = rcPair.second;
            for(pair<int,int> dir : directions){
                int nr = cr + dir.first;
                int nc = cc + dir.second;
                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == INT_MAX){
                    grid[nr][nc] = grid[cr][cc] + 1;
                    q.push({nr,nc});
                }
            }
        }
    }
};
