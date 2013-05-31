class Solution {
public:
    void getPermutation(vector<int> &num, vector<bool> &flag, vector<int> &now, vector<vector<int> > &res, int n)
    {
        if (n==num.size())
        {
            res.push_back(now);
            return ;
        }
        int st = 0;
        for (int i=0; i<num.size(); i++)        
        {            
            if (flag[i]==false) continue;
            if (i>0 && num[i]==num[i-1] && flag[i-1]) continue;
            flag[i] = false;
            now.push_back(num[i]);
            getPermutation(num, flag, now, res, n+1);
            now.pop_back();
            flag[i] = true;
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        vector<bool> flag;
        vector<bool>().swap(flag);
        for (int i=0; i<num.size(); i++)
            flag.push_back(true);
        vector<int> now;
        vector<vector<int> > res;
        getPermutation(num, flag, now, res, 0);
        return res;            
    }
};
