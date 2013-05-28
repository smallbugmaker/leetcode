class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n==0) return 0;
        
        int now = A[0], i=1, m=1;
        while (i<n)
        {
            if (A[i]!=now)
            {
                A[m] = A[i];                
                now = A[i];
                m++;               
            }
            i++;
        }
        return m;
    }
};
