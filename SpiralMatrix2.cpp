class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > matrix;
        vector<int> tmp;
        for (int i=0; i<n; i++)
            tmp.push_back(0);
        for (int i=0; i<n; i++)
            matrix.push_back(tmp);
        
        int now = 1;
        int x = 0, y = 0, t = 0;
        while (now <= n*n)
        {            
            switch (t)
            {
                case 0:
                    while (now<=n*n && y<n && matrix[x][y]==0)
                    {
                        matrix[x][y++] = now++;
                    }      
                    y--;
                    x++;
                    break;
                case 2: 
                    while (now<=n*n && y>=0 && matrix[x][y]==0)
                    {
                        matrix[x][y--] = now++;
                    }      
                    y++;
                    x--;
                    break;                    
                case 1:
                    while (now<=n*n && x<n && matrix[x][y]==0)
                    {
                        matrix[x++][y] = now++;
                    }      
                    x--;
                    y--;
                    break;
                case 3: 
                    while (now<=n*n && x>=0 && matrix[x][y]==0)
                    {
                        matrix[x--][y] = now++;
                    }      
                    x++;
                    y++;
                    break;                                                        
            }        
            t = (t+1)%4;
        }
        return matrix;
    }
};
