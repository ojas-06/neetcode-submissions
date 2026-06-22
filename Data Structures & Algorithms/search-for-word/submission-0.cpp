class Solution {
public:
    bool search(vector<vector<char>>& board, const string& word, int i, int j, int index) {
        if (index == word.size()) return true;
        
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '*';
    
        bool found = search(board, word, i + 1, j, index + 1) ||
                     search(board, word, i - 1, j, index + 1) ||
                     search(board, word, i, j + 1, index + 1) ||
                     search(board, word, i, j - 1, index + 1);
        board[i][j] = temp;
        
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        if (word.length() > m * n) return false;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (search(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};