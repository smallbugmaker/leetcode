class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        
        if (l3 != l1 + l2) return false;
        if (l3 == 0) return true;
        
        vector< vector<bool> > flag;
        vector< vector<bool> >().swap(flag);
        
        for (int i=0; i<=l1; i++)
        {
            vector<bool> temp;
            vector<bool>().swap(temp);
            for (int j=0; j<=l2; j++)
            {                
                temp.push_back(false);
            }
            flag.push_back(temp);
        }
            
        flag[0][0] = true;        
        for (int i=0; i<l1; i++)
        {
            flag[i+1][0] = (flag[i][0] && s1[i]==s3[i]);
        }
        for (int i=0; i<l2; i++)
        {
            flag[0][i+1] = (flag[0][i] && s2[i]==s3[i]);
        }        
        
        for (int i=0; i<l1; i++)
        {
            for (int j=0; j<l2; j++)
            {
                flag[i+1][j+1] = (flag[i][j+1] && s1[i]==s3[i+j+1]) || (flag[i+1][j] && s2[j]==s3[i+j+1]);
            }
        }
        return flag[l1][l2];
    }
};
