class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        vector<int>().swap(res);
        
        res.push_back(1);
        res.push_back(1);
        
        for (int i=2; i<=n; i++)
        {
            res.push_back(0);
            for (int j=1; j<=i; j++)
                res[i] = res[i] + res[j-1]*res[i-j];
        }
        return res[n];
    }
};
