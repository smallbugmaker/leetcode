class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i=0; i<n; i++)
            if (A[i]<=0) A[i] = n+1;
        
        for (int i=0; i<n; i++)
        {
            int value = abs(A[i]);
            if (value<=n && A[value-1]>0)
                A[value-1] = -A[value-1];
        }
        
        for (int i=0; i<n; i++)
            if (A[i]>=0) return i+1;
        return n+1;
    }
};
