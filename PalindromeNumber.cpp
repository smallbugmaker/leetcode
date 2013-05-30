class Solution {
public:
    long long reverse(int x) {
        long long res = 0;
        while (x!=0)
        {
            res = res*10+x%10;
            x = x/10;
        }
        return res;
    }  
    
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x<0) return false;
        long long r = reverse(x);
        if (r==x) return true;
        return false;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x<0) return false;
        int y = x/10, div = 1;
        while (y)
        {
            div = div * 10;
            y = y/10;
        }         
        
        y = x;
        int z = x;
        while (y)
        {
            if (y%10 != z/div) return false;
            y = y/10;
            z = z % div;
            div = div/10;
        }
        return true;
    }
};
