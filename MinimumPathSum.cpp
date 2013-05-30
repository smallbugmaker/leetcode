class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = grid.size();
        if (n==0) return 0;
        int m = grid[0].size();
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (i==0 && j==0) continue;
                int mind = 2147483647;
                if (i>0 && grid[i-1][j]+grid[i][j]<mind)
                    mind = grid[i-1][j]+grid[i][j];
                if (j>0 && grid[i][j-1]+grid[i][j]<mind)
                    mind = grid[i][j-1]+grid[i][j];                
                grid[i][j] = mind;
            }
        }
        return grid[n-1][m-1];
    }
};
