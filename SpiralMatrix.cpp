class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        vector<int>().swap(res);
        int m = matrix.size();
        if (m==0) return res;
        int n = matrix[0].size();   
        
        int tm = m, tn = n;
        m--;
        
        int x = 0, y = -1, t = 0;
        while (tm*tn>0)
        {            
            switch (t)
            {
                case 0:
                for (int i=0; i<n; i++)
                {
                    res.push_back(matrix[x][++y]);                    
                };                 
                n--;
                tm--;
                break;
                case 2: 
                for (int i=0; i<n; i++)
                {
                    res.push_back(matrix[x][--y]);                    
                };                 
                n--;
                tm--;
                break;                
                case 1: 
                for (int i=0; i<m; i++)
                {
                    res.push_back(matrix[++x][y]);                    
                };                 
                m--;
                tn--;
                break;                
                case 3:
                for (int i=0; i<m; i++)
                {
                    res.push_back(matrix[--x][y]);                    
                };                 
                m--;
                tn--;
                break;                
            }
        //    if (m==0 ) break;
            t = (t+1)%4;
        }
        return res;
    }
};
