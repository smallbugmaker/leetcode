class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int st = 0, en = n-1, mid;
        while (st<=en)
        {
            mid = (st+en)/2;
            if (A[mid]==target) return mid;
            if (A[mid]>target)
                en = mid-1;
            else
                st = mid+1;
        }        
        return st;
    }
};
