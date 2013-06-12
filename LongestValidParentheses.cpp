class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> index, bonus;
        int len = s.length(), b = 0, pos = 0, res = 0;
        
        while (pos<len)
        {
            if (s[pos]=='(')
            {
                index.push(pos);
                bonus.push(b);
                b = 0;
            }
            else
            {
                if (!index.empty())
                {
                    int now = pos - index.top() + 1 + bonus.top();
                    if (now>res) res = now;
                    b = now;
                    index.pop();
                    bonus.pop();
                }
                else
                {
                    b = 0;
                }
            }
            pos++;
        }
        return res;
    }
};
