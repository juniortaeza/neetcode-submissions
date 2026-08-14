class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();

        vector<pair<int,int>> directions = { {-1,0},{1,0},{0,-1},{0,1} };
        
        int numIslands = 0;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == '1'){
                    numIslands += 1;
                    grid[r][c] = '0';
                    queue<pair<int,int>> q;
                    q.push({r,c});
                    while(!q.empty()){
                        pair<int,int> rc = q.front(); q.pop();
                        int cr = rc.first, cc = rc.second;
                        for(pair<int,int> dir : directions){
                            int nr = cr + dir.first;
                            int nc = cc + dir.second;
                            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1'){
                                q.push({nr,nc});
                                grid[nr][nc] = '0';
                            }
                        }
                    }
                }
            }
        }

        return numIslands;
    }
};
