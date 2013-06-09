class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int res = 0;
        
        int st = 0, en = height.size()-1;
        
        while (st<en)
        {
            int area = 0;
            if (height[st]<height[en])
            {
                area = height[st]*(en-st);
                st++;
            }
            else
            {
                area = height[en]*(en-st);
                en--;
            }
            if (area>res) res = area;
        }
        return res;
    }
};
