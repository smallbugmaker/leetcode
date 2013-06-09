class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool row[9][9], col[9][9], grid[3][3][9];
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(grid, false, sizeof(grid));        
        int num = 0;
        for (int i=0; i<9; i++)
        {
            for (int j=0; j<9; j++)
                if (board[i][j]!='.')
                {
                    int k = board[i][j]-'1';
                    if (row[i][k] || col[j][k] || grid[i/3][j/3][k]) return false;
                    row[i][k] = true;
                    col[j][k] = true;
                    grid[i/3][j/3][k] = true;
                }                
        } 
        return true;
    }
};
