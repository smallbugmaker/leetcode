class Solution {
public:

    int largestRectangleArea(vector<int> &height, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> left, right;
        vector<int>().swap(left);
        vector<int>().swap(right);
                
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
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        if (m==0) return 0;
        int n = matrix[0].size();
        
        vector< vector<int> > height;
        vector< vector<int> >().swap(height);
        vector<int> h;
        vector<int>().swap(h);
        for (int j=0; j<n; j++)
        {
            if (matrix[0][j]=='1')
                h.push_back(1);
            else
                h.push_back(0);
        }
        int res = largestRectangleArea(h, n);
        height.push_back(h);        
        
        for (int i=1; i<m; i++)
        {               
            for (int j=0; j<n; j++)
            {
                if (matrix[i][j]=='1')
                    h[j] = height[i-1][j]+1;
                else
                    h[j] = 0;
            }
            height.push_back(h);
            int now = largestRectangleArea(h, n);
            if (now>res)
                res = now;
        }        
        return res;        
    }
};
