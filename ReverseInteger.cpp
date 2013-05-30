class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int res = 0;
        while (x!=0)
        {
            res = res*10+x%10;
            x = x/10;
        }
        return res;
    }
};
