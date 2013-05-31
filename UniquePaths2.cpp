class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = obstacleGrid.size();
        if (m==0) return 0;
        int n = obstacleGrid[0].size();        
        vector<vector<int> > res;
        vector<int> r;
        vector<int>().swap(r);
        if (obstacleGrid[0][0]==1) return 0;
        r.push_back(1);
        for (int j=1; j<n; j++)
            if (obstacleGrid[0][j]==0)
                r.push_back(r[j-1]);
            else
                r.push_back(0);
        res.push_back(r);
        
        for (int i=1; i<m; i++)
        {
            
            vector<int>().swap(r);
            r.push_back(0);
            if (obstacleGrid[i][0]==0)
                r[0] = res[i-1][0];            
            for (int j=1; j<n; j++)
            {                
                if (obstacleGrid[i][j]==1)
                {
                    r.push_back(0);
                    continue;
                }                
                r.push_back(res[i-1][j]+r[j-1]);
            }
            res.push_back(r);
        }
        return res[m-1][n-1];
    }
};
