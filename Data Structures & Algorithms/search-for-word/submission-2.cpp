class Solution {
    bool dfs(vector<vector<char>> &board, string& word, int x, int y, int index) {
        if (index == word.size()) return true;
        if (x<0 || y<0 || x>=board.size() || y>=board[0].size()) return false;
        if (board[x][y] != word[index]) return false;
        char temp = board[x][y];
        board[x][y] = '#';
        bool found = dfs(board, word, x+1, y, index+1) || dfs(board, word, x, y+1, index+1) || 
        dfs(board, word, x-1, y, index+1) || dfs(board, word, x, y-1, index+1);
        board[x][y] = temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        for (int i=0;i<row;i++) {
            for (int j=0;j<col;j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
