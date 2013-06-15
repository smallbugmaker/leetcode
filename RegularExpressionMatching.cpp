class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (*p=='\0')
        {
            if (*s=='\0') return true;
            return false;
        }
        if (*(p+1)=='*')
        {
            while (*p==*s || (*p=='.' && *s!='\0'))
            {
                if (isMatch(s, p+2))
                    return true;
                s++;
            }
            return isMatch(s, p+2);
        }
        else
        {
            if (*p==*s || (*p=='.' && *s!='\0'))
                return isMatch(s+1, p+1);
            return false;
        }
    }
};
