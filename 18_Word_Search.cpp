// Revision Count : 0
// Approach : backtracking
// Time Complexity : O(m x n x 4^L) where L = length of word
// Space Complexity : O(L) where L = length of word i.e. the depth of recursion. (Each call adds a new frame to the call stack.)

class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int row, int col, int index) {
    // after traversal, if index successfully reaches till end, that means we found our word
       if(index == word.size()) return true;
    // if we go out of board OR if our current element at board does not matches current
    // element of word at index : index, then return false. No sense of searching further.
       if(row < 0 || col <  0 || row > board.size()-1 || col > board[0].size()-1 || word[index] != board[row][col])
            return false;

       char temp = board[row][col];
    // marking it visited
       board[row][col] = '*';
    // moving up down left or right   
        bool up = solve(board, word, row-1, col, index+1);
        bool down = solve(board, word, row+1, col, index+1);
        bool left = solve(board, word, row, col-1, index+1);
        bool right = solve(board, word, row, col+1, index+1);
    
    // marking it unvisited after traversal. (backtracking)
        board[row][col] = temp;
        return (up || down || left || right);
    }

    bool exist(vector<vector<char>>& board, string word) {
        // trying all possible starts
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(solve(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};