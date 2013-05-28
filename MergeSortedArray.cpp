class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = m+n-1;
        m--;
        n--;
        while (m>=0 && n>=0)
        {
            if (A[m]>B[n])
            {
                A[l] = A[m];
                m--;
            }
            else
            {
                A[l] = B[n];
                n--;
            }
            l--;
        }
        if (n>=0)
        {
            for (int i=n;i>=0;i--)
                A[i] = B[i];
        }
    }
};
