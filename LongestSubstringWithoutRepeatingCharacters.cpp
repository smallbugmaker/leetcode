class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        set<char> contain;
        set<char>().swap(contain);
        map<char, int> count;
        map<char, int>().swap(count);
        
        int res = 0;
        int st = 0, en = 0, len = s.length();
        
        while (en!=len)
        {
            if (contain.find(s[en])!=contain.end())
            {
                if (en-st>res)
                    res = en-st;
                if (count.find(s[en])==count.end())
                    count.insert(make_pair(s[en], 0));
                count[s[en]]++;
                
                while (count.size()!=0)
                {
                    map<char, int>::iterator itr = count.find(s[st]);
                    if (itr!=count.end())
                    {
                        count[s[st]]--;
                        if (count[s[st]]==0) count.erase(itr);
                    }
                    else
                        contain.erase(s[st]);
                    st++;
                }
            }
            else
            {
                contain.insert(s[en]);                
            }
            en++;
        }
        if (en-st>res)
            res = en-st;
        return res;
    }
};
