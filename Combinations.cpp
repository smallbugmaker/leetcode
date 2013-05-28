class Solution {
public:
    void getresult(int st, int n, int k, vector<bool> &flag, vector<int> &now, vector< vector<int> > &res)
    {
        if (k==0)
        {
            res.push_back(now);
            return;
        }
        for (int i=st; i<=n; i++)
        {
            if (flag[i])
            {
                flag[i] = false;
                now.push_back(i);
                getresult(i+1, n, k-1, flag, now, res);
                now.pop_back();
                flag[i] = true;
            }            
        }
    }
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> now;
        vector<int>().swap(now);
        vector< vector<int> > res;
        vector< vector<int> >().swap(res);
        vector<bool> flag;
        for (int i=0; i<=n; i++)
            flag.push_back(true);
        getresult(1, n, k, flag, now, res);
        return res;        
    }
};

