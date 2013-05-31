class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n<=1) return true;
        int last = A[0];
        for (int i=1; i<n; i++)
        {
            if (last<=0) return false;
            last = max(last-1, A[i]);            
        }
        return true;
    }
};
