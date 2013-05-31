class Solution {
public:
    void getresult(vector<int> &candidates, int lack, int st, vector<int> &now, vector<vector<int> > &res)
    {
        if (lack==0)
        {
            res.push_back(now);
            return;
        }
        
        for (int i=st; i<candidates.size(); i++)
        {
            if (candidates[i]>lack) break;
            now.push_back(candidates[i]);
            getresult(candidates, lack-candidates[i], i, now, res);
            now.pop_back();            
        }
    }
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> now;
        vector<vector<int> > res;
        sort(candidates.begin(), candidates.end());
        getresult(candidates, target, 0, now, res);
        return res;
    }
};
