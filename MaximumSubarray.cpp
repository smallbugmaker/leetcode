class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function        
        vector<int> M;
        vector<int>().swap(M);
        if (A[0]<0) M.push_back(0);
        else M.push_back(A[0]);
        int res = A[0];
        
        for (int i=1; i<n; i++)
        {            
            if (M[i-1]+A[i]<0)
            {
                M.push_back(0);
                if (A[i]>res) res = A[i];
            }
            else
            {
                M.push_back(M[i-1]+A[i]);
                if (M[i]>res) res = M[i];
            }
        }
        return res;
    }
};
