class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return -1;
        int rows = grid.size();
        int cols = grid[0].size();

        // count fresh fruit and record rotten fruit locations
        queue<pair<int,int>> q;
        int freshFruit = 0;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 1)
                    freshFruit += 1;
                else if(grid[r][c] == 2)
                    q.push({r,c});
            }
        }

        // run bfs beginning with rotten fruits, and count layers (minutes)
        vector<pair<int,int>> directions = { {-1,0},{1,0},{0,-1},{0,1} };
        int minutes = 0;
        while(freshFruit > 0 && !q.empty()){
            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++){
                pair<int,int> rcPair = q.front(); q.pop();
                int cr = rcPair.first;
                int cc = rcPair.second;
                for(pair<int,int> dir : directions){
                    int nr = cr + dir.first;
                    int nc = cc + dir.second;
                    if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        freshFruit -= 1;
                        q.push({nr,nc});
                    }
                }
            }
            minutes += 1;
        }

        return freshFruit == 0 ? minutes : -1;
    }
};