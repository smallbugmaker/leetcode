class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (strs.size()==0) return "";
        
        vector<int> c;
        for (int j=0; j<strs[0].length(); j++)
            c.push_back(1);
            
        for (int i=1; i<strs.size(); i++)
        {
            for (int j=0; j<strs[i].length() && j<strs[0].length(); j++)
                if (strs[i][j]==strs[0][j])
                    c[j]++;
                else
                    break;
        }
        
        string res = "";
        for (int j=0; j<strs[0].length(); j++)
            if (c[j]==strs.size())
                res+=strs[0][j];
            else
                break;
        return res;        
    }
};
