class Solution {
public:
    void getSubset(vector<int> &S, int st, vector<int> &now, vector<vector<int> > &res)
    {
        int n = S.size();
        while (st < n)
        {
            int i = 1;
            now.push_back(S[st]);
            res.push_back(now);
            getSubset(S, st+1, now, res);
            now.pop_back();            
            st++;
        }
    }

    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        vector<vector<int> > res;
        vector<vector<int> >().swap(res);        
        vector<int> now;
        vector<int>().swap(now);
        res.push_back(now);
        getSubset(S, 0, now, res);
        return res;
    }
};
