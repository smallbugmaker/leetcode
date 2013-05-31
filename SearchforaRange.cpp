class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int begin = -1, end = -1;
        int st = 0, en = n-1, mid;
        while (st<=en)
        {
            mid = (st+en)/2;            
            if (A[mid]>=target)
                en = mid-1;
            else
                st = mid+1;
        }        
        begin = en+1;
        st = 0, en = n-1;
        while (st<=en)
        {
            mid = (st+en)/2;            
            if (A[mid]>target)
                en = mid-1;
            else
                st = mid+1;
        }        
        end = st-1;
                
        if (A[begin]!=target)
        {
            begin = -1;
            end = -1;
        }
        vector<int> res;
        res.push_back(begin);
        res.push_back(end);
        return res;        
    }
};
