class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        if (m==0) return false;
        int n = matrix[0].size();
        int rowst = 0, rowen = m-1, colst = 0, colen = n-1, row = 0;
        
        while (rowst<rowen)
        {
            int mid = (rowst+rowen)/2;
            if (matrix[mid][0]==target) return true;
            if (matrix[mid][0]>target)
            {
                rowen = mid-1;                                
            }
            else
            {
                rowst = mid+1;
            }            
        }        
        row = rowst;
        if (matrix[row][0]>target) row--;
        
        while (row>=0 && colst<=colen)
        {
            int mid = (colst+colen)/2;
            if (matrix[row][mid]==target) return true;
            if (matrix[row][mid]>target)
                colen = mid-1;
            else
                colst = mid+1;
        }
        return false;        
    }
};
