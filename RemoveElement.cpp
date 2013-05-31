class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        while (i<n)
        {
            if (A[i]==elem)
            {
                int tmp = A[i];
                A[i] = A[n-1];
                A[n-1] = tmp;
                n--;
            }
            else
                i++;
        }
        return n;
    }
};
