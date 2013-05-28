class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s1.length()!=s2.length()) return false;
        
        int n = s1.length();
        bool res[100][100][100];
        
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (s1[i]==s2[j])
                    res[1][i][j] = true;
                else
                    res[1][i][j] = false;
        
        for (int k=2; k<=n; k++)
        {
            for (int i=0; i<n; i++)
            {
                if (i+k>n) break;
                for (int j=0; j<n; j++)
                {
                    if (j+k>n) break;
                    for (int r=1; r<k; r++)
                    {
                        res[k][i][j] = (res[r][i][j] && res[k-r][i+r][j+r]) || (res[r][i][j+k-r] && res[k-r][i+r][j]);
                        if (res[k][i][j]) break;
                    }
                }
            }
        }
        return res[n][0][0];
    }
};
