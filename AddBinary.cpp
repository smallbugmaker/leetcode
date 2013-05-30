class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int posa = a.length()-1, posb = b.length()-1;
        string res = "";
        bool flag = false;
        while (posa>=0 && posb>=0)
        {
            if (a[posa]=='1' && b[posb]=='1')
            {
                if (flag)
                    res = '1'+res;
                else
                    res  = '0' + res;
                flag = true;
                
            }
            else
                if (a[posa]=='0' && b[posb]=='0')
                {                
                    if (flag)
                        res = '1' + res;
                    else
                        res = '0' + res;
                    flag = false;
                }
                else
                {
                    if (flag)
                        res = '0' +res;
                    else                  
                        res = '1' + res;
                }
            posa--;
            posb--;
        }
        while (posa>=0)
        {
            if (flag)
            {
                if (a[posa]=='1')
                {
                    flag = true;
                    res = '0'+res;
                }
                else
                {
                    flag = false;
                    res = '1'+res;
                }
            }
            else
                res = a[posa]+res;
            posa--;
        }
        while (posb>=0)
        {
            if (flag)
            {
                if (b[posb]=='1')
                {
                    flag = true;
                    res = '0'+res;
                }
                else
                {
                    flag = false;
                    res = '1'+res;
                }
            }
            else
                res = b[posb]+res;
            posb--;
        }
        if (flag) res = '1'+res;
        return res;
    }
};
