class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> st;
        while (!st.empty())
            st.pop();
        
        for (int i=0; i<s.length(); i++)
        {
            switch (s[i])
            {
                case '(': 
                case '{': 
                case '[': st.push(s[i]); break;
                case ')':
                    if (st.empty() || st.top()!='(') return false;
                    st.pop();
                    break;
                case '}':
                    if (st.empty() || st.top()!='{') return false;
                    st.pop();
                    break;
                case ']':
                    if (st.empty() || st.top()!='[') return false;
                    st.pop();
                    break;
            }
        }
        if (st.empty()) return true;
        else
            return false;
    }
};
