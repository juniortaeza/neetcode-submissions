class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> row; // row
        unordered_map<int, unordered_set<int>> col; // column
        unordered_map<int, unordered_set<int>> sub; // subsquare (3x3)

        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){
                // grab current cell
                char cell = board[r][c];

                // skip if empty cell
                if(cell == '.')
                    continue;

                // perform check 1 - no duplicate in row
                if(row[r].count(cell))
                    return false;

                // perform check 2 - no duplicate in col
                if(col[c].count(cell))
                    return false;

                // perform check 3 - no duplicate in 3x3 subsquare
                int subsquareIndex = (r/3)*3 + (c/3);
                if(sub[subsquareIndex].count(cell))
                    return false;

                // otherwise, update hashmap accordingly
                row[r].insert(cell);
                col[c].insert(cell);
                sub[subsquareIndex].insert(cell);
            }
        }

        return true;
    }
};
