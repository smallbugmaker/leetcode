class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> left;
        vector<int>().swap(left);
        
        left.push_back(0);
        for (int i=1; i<n; i++)
        {
            left.push_back(A[i-1]-A[i]+left[i-1]);     
            left[i] = max(0, left[i]);
        }
        
        int res = 0, right = 0;
        for (int i=n-2; i>0; i--)
        {
            right = right+A[i+1]-A[i];  
            right = max(0, right);
            res += min(left[i], right);
        }
        return res;
    }
};
