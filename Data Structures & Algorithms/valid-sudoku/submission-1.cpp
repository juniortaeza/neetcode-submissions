class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> row;
        unordered_map<int, unordered_set<int>> col;
        unordered_map<int, unordered_set<int>> sub;

        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){
                char cell = board[r][c];

                // if empty space, go to next cell
                if(cell == '.')
                    continue;

                // perform check 1
                if(row[r].count(cell) != 0)
                    return false;

                // perform check 2
                if(col[c].count(cell) != 0)
                    return false;

                // perform check 3
                int subIndex = (r/3)*3 + (c/3);
                if(sub[subIndex].count(cell) != 0)
                    return false;

                row[r].insert(cell);
                col[c].insert(cell);
                sub[subIndex].insert(cell);
            }
        }
        return true;
    }
};
