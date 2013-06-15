class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int st = 0, en = 0, res = 0;
        while (st<=en)
        {
            if (st>=n-1) return res;
            res++;
            int newen = 0;
            for (int i=st; i<=en; i++)
            {
                if (i+A[i]>newen) newen = i+A[i];
                if (i+A[i]>=n-1) return res;
            }
            en = newen;
            st++;
        }
        return res;
    }
};
