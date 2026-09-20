class Solution {
private:
    void search(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int i, int r, int c, bool& wordFound) {
        if(i == word.size())              { wordFound = true; return; }
        if(r < 0 || r >= board.size())    { return; }
        if(c < 0 || c >= board[0].size()) { return; }  
        if(board[r][c] != word[i])        { return; }
        if(visited[r][c])                 { return; }

        visited[r][c] = true;
        search(board, visited, word, i+1, r-1, c, wordFound);
        search(board, visited, word, i+1, r+1, c, wordFound);
        search(board, visited, word, i+1, r, c-1, wordFound);
        search(board, visited, word, i+1, r, c+1, wordFound);
        visited[r][c] = false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(board[r][c] == word[0]){
                    bool wordFound = false;
                    search(board, visited, word, 0, r, c, wordFound);
                    if(wordFound) return true;
                }
            }
        }
        return false;
    }
};
