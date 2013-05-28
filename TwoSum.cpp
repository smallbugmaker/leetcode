class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> copy(numbers);
    
        int n = numbers.size();
        int st = 0, en = n-1;
        
        sort(numbers.begin(), numbers.end());
        while (numbers[st]+numbers[en]!=target)
        {            
            while (en>st && numbers[st]+numbers[en]>target)
                en--;
            if (numbers[st]+numbers[en]==target)
               break;
            st++;
            while (en<n && numbers[st]+numbers[en]<target)
               en++;
            if (en<n && numbers[st]+numbers[en]==target)
               break;
            if (en==n) en--;
        }
        int newst=st, newen=en;
        for (int i=0;i<n;i++)
            if (copy[i]==numbers[st])
            {
                newst = i+1;
                copy[i] = -1;
            }
            else
                if (copy[i]==numbers[en])
                {
                   newen = i+1;
                   copy[i] = -1;
                }
        vector<int> res;
        if (newst>newen)
        {
            int t = newst;
            newst = newen;
            newen = t;
        }
        res.push_back(newst);
        res.push_back(newen);
        return res;
    }
};

