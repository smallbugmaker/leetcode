class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n<2) return 1;
        
        int l = 1, ll = 1;
        int res = 0;
        for (int i=1; i<n; i++)
        {
            res = l+ll;
            ll = l;
            l = res;
        }
        return res;
    }
};
