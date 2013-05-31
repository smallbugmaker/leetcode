class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n==0) return "";
        string s[2];
        s[0] = "1";
        s[1] = "";
        int t = 0;
        
        while (--n)
        {
            t = 1-t;
            int pos = 0;
            s[t] = "";
            char pre = ' ';
            int count = 0;
            while (pos<=s[1-t].length())
            {
                if (pos==s[1-t].length())
                {
                    char tmp[10];
                    sprintf(tmp,"%d%c",count, pre);                    
                    s[t] += tmp;
                }
                else
                    if (pre==s[1-t][pos])
                    {
                        count++;
                    }
                    else
                    {
                        if (count>0)
                        {
                            char tmp[10];
                            sprintf(tmp,"%d%c",count, pre);                    
                            s[t] += tmp;                            
                        }               
                        pre = s[1-t][pos];
                        count = 1;
                    }
                pos++;
            }  
        }
        return s[t];
    }
};
