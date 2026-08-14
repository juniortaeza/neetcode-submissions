class Solution {
private:
    void backtrack(const vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int i, int r, int c, bool& wordFound){
        // Base case
        if(i == word.size()) { wordFound = true; return; }

        // Check bounds
        if(r < 0 || r >= board.size())    { return; }
        if(c < 0 || c >= board[0].size()) { return; }

        // Check valid cell
        if(board[r][c] != word[i])        { return; }
        if(visited[r][c])                 { return; }

        // Set cell as visited
        visited[r][c] = true;

        // Explore four directions (up, down, left, right)
        backtrack(board, word, visited, i+1, r-1, c, wordFound);
        backtrack(board, word, visited, i+1, r+1, c, wordFound);
        backtrack(board, word, visited, i+1, r, c-1, wordFound);
        backtrack(board, word, visited, i+1, r, c+1, wordFound);
        
        // Backtrack - set cell as unvisited when unwinding
        visited[r][c] = false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        if(rows == 0) return false;
        int cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        bool wordFound = false;

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(board[r][c] == word[0]){
                    backtrack(board, word, visited, 0, r, c, wordFound);
                    if(wordFound) return true;
                }
            }
        }

        return false;
    }
};
