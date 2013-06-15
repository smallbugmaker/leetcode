class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = matrix.size();
        for (int i=0; i<n; i++)
            for (int j=0; j<n-i-1; j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][n-i-1];
                matrix[n-j-1][n-i-1] = tmp;
            }
        for (int i=0; i<n/2; i++)
            for (int j=0; j<n; j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-i-1][j];
                matrix[n-i-1][j] = tmp;
            }
    }
};
