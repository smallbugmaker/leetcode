class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int pos = strlen(s)-1;
        while (pos>=0 && s[pos]==' ' ) pos--;
        int res = 0;
        while (pos>=0 && s[pos]!=' ')
        {
            pos--;
            res++;
        }
        return res;
    }
};
