class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        if (len==0) return 0;
        
        vector<int> res;
        vector<int>().swap(res);
        
        res.push_back(1);
        if ((s[0]-'0')>0 && (s[0]-'0')<27)
           res.push_back(1);
        else 
           res.push_back(0);           
        
        
        for (int i=1; i<len; i++)
        {
            res.push_back(0);
            if ((s[i]-'0')>0 && (s[i]-'0')<=26)
                res[i+1] += res[i];
            if (s[i-1]!='0')
            {
                int n = (s[i-1]-'0')*10+(s[i]-'0');
                if (n>0 && n<=26) 
                    res[i+1] += res[i-1];
            }
        }
        return res[len];
    }
};
