class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int boost = 1;
        for (int i=digits.size()-1; i>=0; i--)
        {
            int tmp = digits[i]+boost;
            boost = tmp/10;
            digits[i] = tmp%10;
        }
        if (boost!=0)
            digits.insert(digits.begin(), boost);
        return digits;
    }
};
