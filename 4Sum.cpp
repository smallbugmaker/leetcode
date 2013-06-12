class Solution {
public:
    
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
                
        vector<vector<int> > res;        
        int n = num.size();
        
        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                int st = j+1, en = n-1;
                while (st<en)
                {
                    int sum = num[i]+num[j]+num[st]+num[en];
                    if (sum==target)
                    {
                        vector<int> r;
                        vector<int>().swap(r);
                        r.push_back(num[i]);
                        r.push_back(num[j]);
                        r.push_back(num[st]);
                        r.push_back(num[en]);
                        res.push_back(r);
                        st++;
                        en--;
                    }
                    else
                        if (sum>target) en--;
                        else st++;                        
                }
            }
        }
        sort(res.begin(), res.end());
        res.resize(unique(res.begin(), res.end())-res.begin());        
        return res;
    }    
};


