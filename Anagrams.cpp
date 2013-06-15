class Solution {
public:
    
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = strs.size();
        map<string, vector<string> > h;
        vector<string> res;
        vector<string>().swap(res);
        for (int i=0; i<n; i++)
        {
            string s(strs[i]);
            sort(s.begin(), s.end());
            if (h.find(s)==h.end())
               h.insert(make_pair(s, res));
            h[s].push_back(strs[i]);
        }
        
        map<string, vector<string> >::iterator itr = h.begin();
        while (itr!=h.end())
        {
            if (itr->second.size()>1)
            {
                res.insert(res.end(), itr->second.begin(), itr->second.end());
            }
            itr++;
        }
        return res;        
    }
};
