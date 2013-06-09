class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        map<int, int> count;
        map<int, int>().swap(count);
        for (int i=0; i<num.size(); i++)
        {
            if (count.find(num[i])!=count.end())
                count.insert(make_pair(num[i], 0));
            count[num[i]]++;
        }
        
        vector<vector<int> > res;
        vector<int> r;
        
        for (int i=0; i<num.size(); i++)
        {
            if (i>0 && num[i]==num[i-1]) continue;
            r.clear();
            r.push_back(num[i]);
            int t = 0 - num[i];
            count[num[i]]--;
            
            for (int j=i+1; j<num.size(); j++)
            {
                if (j>i+1 && num[j]==num[j-1]) continue;
                if (num[j]*2>t) break;
                count[num[j]]--;
                map<int, int>::iterator itr = count.find(t-num[j]);
                if (itr!=count.end() && itr->second>0)
                {
                    r.push_back(num[j]);
                    r.push_back(t-num[j]);
                    res.push_back(r);
                    r.pop_back();
                    r.pop_back();
                }
                count[num[j]]++;                
            }
            count[num[i]]++;
        }
        return res;
    }
};
