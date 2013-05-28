class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n<=2) return n;
        
        int pre = A[0], now = A[1], i=2, m=2;
        while (i<n)
        {
            if (A[i]!=pre || A[i]!=now)
            {
                A[m] = A[i];
                pre = now;
                now = A[i];
                m++;               
            }
            i++;
        }
        return m;
    }
};
