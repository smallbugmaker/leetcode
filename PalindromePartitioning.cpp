/*************************************************************************
Author: HongYihong
Created Time: Fri 03 May 2013 03:53:24 PM CST
File Name: Work/code/leetcode/PalindromePartitioning.cpp
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
    bool isPalindrome(string s, int st, int en, vector< vector<int> > &flag)
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

    void DFS(string s, int st, vector<vector<int> > &flag, vector< vector<string> > &res, vector<string> par)
    {
        if (st == s.length())
        {
            res.push_back(par);
            return ;
        }
        for (int i = st; i < s.length(); i++)
        {
            if (isPalindrome(s, st, i, flag))
            {
                par.push_back(s.substr(st, i-st+1));
                DFS(s, i+1, flag, res, par);
                par.pop_back();
            }
        }
    }


    vector<vector<string> > partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector<int> > flag;
        vector< vector<int> >().swap(flag);
        for (int i = 0; i < s.length(); i++)
        {
            vector<int> temp;
            vector<int>().swap(temp);
            for (int j = 0; j < s.length(); j++)
              temp.push_back(0);
            flag.push_back(temp);
            flag[i][i] = 1;
        }

        vector<vector<string> > res;
        vector<vector<string> >().swap(res);
        vector<string> par;
        vector<string>().swap(par);
        
        DFS(s, 0, flag, res, par);
        for (int i=0;i<res.size();i++)
        {
            for (int j=0;j<res[i].size();j++)
              cout << res[i][j] << "  ";
            cout << endl;
        }  
        return res;
    }
};

int main()
{
    Solution a;
    string s = "aabbaa";
    cout << s << endl;
    a.partition(s);
}                   
