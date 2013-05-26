class Solution {
public:
    void getIp(string &s, int st, int n, string now, vector<string> &res)
    {
        if (st==s.length() && n==4)
        {
            res.push_back(now.substr(1, now.length()-1));
            return;
        }
        if (st+1<=s.length())
        {
            int temp = atoi(s.substr(st, 1).c_str());
            if (temp>=0 && temp<=255) 
                getIp(s, st+1, n+1, now+'.'+s.substr(st,1), res);
        }
        if (st+2<=s.length() && s[st]!='0')
        {
            int temp = atoi(s.substr(st, 2).c_str());
            if (temp>=0 && temp<=255) 
                getIp(s, st+2, n+1, now+'.'+s.substr(st,2), res);
        }
        if (st+3<=s.length() && s[st]!='0')
        {
            int temp = atoi(s.substr(st, 3).c_str());
            if (temp>=0 && temp<=255) 
                getIp(s, st+3, n+1, now+'.'+s.substr(st,3), res);
        }           
        
    }
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        if (s.length()<4 || s.length()>12) return res;
        getIp(s, 0, 0, "", res);
        return res;
    }
};
