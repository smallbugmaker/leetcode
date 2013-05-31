class Solution {
public:
    void getresult(vector<int> &num, int lack, int st, vector<int> &now, vector<vector<int> > &res)
    {
        if (lack==0)
        {
            res.push_back(now);
            return;
        }
        
        int i = st;
        while (i<num.size())
        {
            if (num[i]>lack) break;            
            now.push_back(num[i]);
            getresult(num, lack-num[i], i+1, now, res);
            i++;
            while (i<num.size() && num[i]==num[i-1]) i++;
            now.pop_back();            
        }
    }
    
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> now;
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        getresult(num, target, 0, now, res);
        return res;
    }    
};
