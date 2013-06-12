// 1908 milli secs
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = L.size();
        vector<int> res;
        vector<int>().swap(res);
        if (n==0) return res;
        
        map<string, int> hash;
        map<string, int>().swap(hash);
        for (int i=0; i<n; i++)
        {
            if (hash.find(L[i])==hash.end())
            {
                hash.insert(make_pair(L[i], 0));
            }
            hash[L[i]]++;
        }        
        
        int l = L[0].length(), slen = S.length();        
        for (int i=0; i<slen && i+n*l<=slen; i++)
        {
            int j = i;            
            bool flag = true;
            map<string, int> h;
            map<string, int>().swap(h);
            for (int k=0; k<n; k++)
            {
                string s = S.substr(j+k*l, l);
                if (hash.find(s)!=hash.end()) 
                {
                    if (h.find(s)==h.end())
                        h.insert(make_pair(s, 0));                        
                    h[s]++;
                    if (h[s]>hash[s])
                    {
                        flag = false;
                        break;
                    }
                }
                else
                {   
                    flag = false;
                    break;
                }
            }
            if (flag)
            {                
                res.push_back(i);                
            }
        }
        return res;
    }
};


