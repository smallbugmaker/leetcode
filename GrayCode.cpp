class Solution {
public:
    void getGrayCode(int m, int n, int value, vector<int> &s, map<int, bool> &dict, vector<int> &res)
    {
        if (res.size()==m) return;
        int t = 1;
        for (int i=0; i<n; i++)
        {
            int pre = s[i];
            s[i] = 1-s[i];            
            int r = value + (s[i]-pre)*t;
            if (dict.find(r)==dict.end())
            {
                dict.insert(make_pair(r, true));
                res.push_back(r);
                getGrayCode(m, n, r, s, dict, res);
                break;
            }
            s[i] = pre;
            t = t*2;
        }
    }
    
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        vector<int>().swap(res);
        res.push_back(0);
        if (n==0) return res;
        
        vector<int> s;
        vector<int>().swap(s);
        int m = 1;
        for (int i=0;i<n;i++)
        {
            s.push_back(0);                        
            m = m * 2;
        }
        map<int, bool> dict;
        map<int, bool>().swap(dict);
        dict.insert(make_pair(0,true));        
        
        getGrayCode(m, n, 0, s, dict, res);
        return res;
    }
};
