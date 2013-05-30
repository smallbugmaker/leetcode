class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long st = 0, en = x/2, mid=0;
        
        while (st<=en)
        {
            mid = (st+en)/2;
            if (mid*mid<=x && (mid+1)*(mid+1)>x) return mid;
            if (mid*mid>x)
            {
                en = mid-1;
            }
            else
            {
                st = mid+1;
            }
        }
        
        return st;
    }
};

