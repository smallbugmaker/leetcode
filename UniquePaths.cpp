class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (m==0 && n==0) return 0;
        vector<vector<int> > res;
        vector<int> r;
        vector<int>().swap(r);
        for (int j=0; j<n; j++)
            r.push_back(1);
        res.push_back(r);
        
        for (int i=1; i<m; i++)
        {
            
            vector<int>().swap(r);
            r.push_back(1);
            for (int j=1; j<n; j++)
            {                
                r.push_back(res[i-1][j]+r[j-1]);
            }
            res.push_back(r);
        }
        return res[m-1][n-1];
    }
};
