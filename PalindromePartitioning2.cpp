/*************************************************************************
Author: HongYihong
Created Time: Fri 03 May 2013 03:53:24 PM CST
File Name: Work/code/leetcode/PalindromePartitioning2.cpp
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
        bool isPalindrome(string &s, int st, int en, vector< vector<int> > &flag)
        {
            if (st > en) return true;
            if (flag[st][en] != 0)
              return (flag[st][en]>0);

            if (s[st]==s[en])
            {
                if ( isPalindrome(s, st+1, en-1, flag) )
                  flag[st][en] = 1;
                else
                  flag[st][en] = -1;
            }
            else
              flag[st][en] = -1;
            return (flag[st][en]>0);
        }

        int minCut(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function

            vector< vector<int> > flag;
            vector< vector<int> >().swap(flag);
            vector<int> res;
            vector<int>().swap(res);

            int len = s.length();
            vector<int> temp;
            vector<int>().swap(temp);
            for (int j = 0; j < len; j++)
              temp.push_back(0);
            
            flag.push_back(temp); 
            for (int i = 0; i < len; i++)
            {
                flag.push_back(temp); 
                flag[i][i] = 1;
                res.push_back(2147483647);
            }

            for (int i = 0; i < len; i++)
            {
                if (isPalindrome(s, 0, i, flag))
                {
                    res[i] = 1;
                    continue;
                }
                for (int j = 0; j < i; j++)
                {
                    int resTmp;
                    if (isPalindrome(s, j+1, i, flag))
                      resTmp = res[j]+1;
                    else
                      resTmp = res[j] + i - j;
                    if (resTmp < res[i])
                      res[i] = resTmp;
                }
            }

            for (int i=0;i<res.size();i++)
            {
                cout << res[i] << " ";
                cout << endl;
            }  
            return res[len-1]-1;
        }
};

int main()
{
    Solution a;
    string s = "aabaa";
    cout << s << endl;
    a.minCut(s);
}                   
