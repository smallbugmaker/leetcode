/*************************************************************************
Author: HongYihong
Created Time: Fri 01 Mar 2013 10:17:02 PM CST
File Name: Code/code/leetcode/LongestPalindromicSubstring.cpp
Description: 
 ************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <cstring>
#include <utility>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

class Solution {
    public:
        string longestPalindrome(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            
            string str = "";
            str += '_';
            for (int i=0; i<s.length(); i++)
            {
                str += s[i];
                str += '_';
            }
         //   cout << str << endl;
            int len = str.length();
            int resi = 0, maxlen = 0;

            for (int i = 0; i < len; i++)
            {
                int res = 0;
                int l = i-1, r = i+1;
                while (l>=0 && r<len && str[l]==str[r])
                {
                    l--;
                    r++;
                    res++;
                }
                if (res>maxlen)
                {
                    maxlen = res;
                    resi = i;
                }
            }
            string sres = "";
            for (int i=resi-maxlen; i<=resi+maxlen; i++)
              if (str[i]!='_')
                sres += str[i];
            return sres;
        }
};

int main()
{
    Solution s;
    cout << s.longestPalindrome("a") << endl;
    cout << s.longestPalindrome("bb") << endl;
    cout << s.longestPalindrome("ccc") << endl;
    cout << s.longestPalindrome("abb") << endl;
    return 0;
}
