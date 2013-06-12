class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int n = strlen(haystack), m = strlen(needle);
        if (m==0) return haystack;
        
        vector<int> next;
        next.push_back(-1);        
        int j = -1;
        for (int i=1; i<m; i++)
        {
            while (j>=0 && needle[i]!=needle[j+1]) j = next[j];
            if (needle[j+1]==needle[i])
                j++;
            next.push_back(j);
        }
        j = -1;
        for (int i=0; i<n; i++)
        {
            while (j>=0 && haystack[i]!=needle[j+1]) j = next[j];
            if (needle[j+1]==haystack[i]) j++;
            if (j==m-1) return haystack+(i-m+1);
        }
        return NULL;
    }
};
