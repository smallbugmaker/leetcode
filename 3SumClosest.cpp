class Solution {
public:
    bool find(vector<int> &num, int target, map<int, int> & count)
    {
        for (int i=0; i<num.size(); i++)
        {
            if (i>0 && num[i]==num[i-1]) continue;
            
            int t = target - num[i];
            count[num[i]]--;
            
            for (int j=i+1; j<num.size(); j++)
            {
                if (j>i+1 && num[j]==num[j-1]) continue;
                if (num[j]*2>t) break;
                count[num[j]]--;
                map<int, int>::iterator itr = count.find(t-num[j]);
                if (itr!=count.end() && itr->second>0)                
                {
                    count[num[i]]++; 
                    count[num[j]]++;                
                    return true;
                }
                count[num[j]]++;
            }
            count[num[i]]++; 
        }
        return false;
    }
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        map<int, int> count;        
        for (int i=0; i<num.size(); i++)
        {
            if (count.find(num[i])!=count.end())
                count.insert(make_pair(num[i], 0));
            count[num[i]]++;
        }
        
        int res = 1;
        if (find(num, target, count)) return target;
        while (1)
        {            
            if (find(num, target+res, count)) return target+res;
            if (find(num, target-res, count)) return target-res;            
            res++;
        }
        return 0;    
    }
};
