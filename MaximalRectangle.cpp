class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        if (m==0) return 0;
        int n = matrix[0].size();
        
        int stx = m-1, sty =n-1, enx = 0, eny = 0;        
        
        bool flag = false;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (matrix[i][j]=='1')
                {
                    if (i<stx) stx = i;
                    if (j<sty) sty = j;
                    if (i>enx) enx = i;
                    if (j>eny) eny = j;
                    flag = true;
                }
            }
        }
        if (flag) return (eny-sty+1)*(enx-stx+1);
        else
            return 0;
    }
};
