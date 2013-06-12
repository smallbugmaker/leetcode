class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector<string> >res;
        vector< vector<string> >().swap(res);
        vector<string> r;
        r.push_back("()");
        res.push_back(r);
        
        for (int i=2; i<=n; i++)
        {
            vector<string>().swap(r);
            for (int j=0; j<res[i-2].size(); j++)
            {
                r.push_back("("+res[i-2][j]+")");
            }
            
            for (int j=1; j<i; j++)
            {
                for (int ii=0; ii<res[j-1].size(); ii++)
                    for (int jj=0; jj<res[i-j-1].size(); jj++)
                        r.push_back(res[j-1][ii]+res[i-j-1][jj]);
            }
            sort(r.begin(), r.end());
            r.resize(unique(r.begin(), r.end())-r.begin());
            res.push_back(r);
        }            
        return res[n-1];
    }
};
