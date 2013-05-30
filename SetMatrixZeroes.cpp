class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.size()==0) return;
        
        bool x = false, y = false;
        for (int i=0; i<matrix.size(); i++)
        {
            if (matrix[i][0]==0)
            {
                x = true;
                break;
            }
        }    

        for (int j=0; j<matrix[0].size(); j++)
        {
            if (matrix[0][j]==0)
            {
                y = true;
                break;
            }
        }            

        for (int i=1; i<matrix.size(); i++)
        {
            for (int j=1; j<matrix[i].size(); j++)
            {
                if (matrix[i][j]==0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i=1; i<matrix.size(); i++)
        {
            for (int j=1; j<matrix[i].size(); j++)
            {
                if (matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j] = 0;                
                }
            }
        }
        
        if (x==true)
        {
            for (int i=0; i<matrix.size(); i++)
                matrix[i][0]=0;            
        }
        if (y==true)
        {
            for (int j=0; j<matrix[0].size(); j++) 
                matrix[0][j]=0;
        }         
    }
};
