class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int digits[7] = {1,5,10,50,100,500,1000};
        char romans[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        
        int res = 0;
        int last = -1, tmpV = 0;
        for (int i=0; i<s.length(); i++)
        {
            int j = 0;
            for (j=0;j<7;j++)
                if (romans[j]==s[i])
                   break;
            int now = digits[j];
            if (last==-1)
            {
                tmpV = now;             
            }
            else
            {
                if (now==last) tmpV+=now;
                else 
                   if (now>last)
                   {
                       res += now-tmpV;
                       tmpV = 0;
                   }
                   else
                   {
                       res +=tmpV;
                       tmpV = now;
                   }
            } 
            last = now;
        }
        if (tmpV>0) res +=tmpV;
        return res;
    }
};
