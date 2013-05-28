class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> left, right;
        vector<int>().swap(left);
        vector<int>().swap(right);
        
        int n = height.size();
        for (int i=0; i<n; i++)
        {
            left.push_back(i);
            right.push_back(i);
        }
        for (int i=0; i<n; i++)
        {
            while ((left[i]-1)>=0 && height[left[i]-1]>=height[i])
                left[i] = left[left[i]-1];            
        }
        for (int i=n-1; i>=0; i--)
        {
            while ((right[i]+1)<n && height[right[i]+1]>=height[i])
                right[i] = right[right[i]+1];            
        }
        int res = 0;
        for (int i=0; i<n; i++)
        {
            int now = (right[i]-left[i]+1)*height[i];
            if (now>res) res = now;
        }
        return res;
    }
};
