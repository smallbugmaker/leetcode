/*************************************************************************
TLE
Author: HongYihong
Created Time: Mon 17 Dec 2012 10:56:26 PM CST
File Name: Code/code/Wildcard.cpp
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

        bool charMatch(char s, char p)
        {
            if (s==p || s=='*' || p=='*' || p=='?' || s=='?')
              return true;
            return false;
        }

        bool isMatch(const char *s, const char *p) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            //
            int lens = strlen(s);
            int lenp = strlen(p);
            int st = 0;
            while (st<lens && st<lenp && s[st]==p[st] && s[st]!='*' && s[st]!='?') st++;
            if (st==lens && st==lenp) return true;
            int en = 1;
            while (lens-en>=0 && lenp-en>=0 && s[lens-en]==p[lenp-en] && s[lens-en]!='*' && s[lens-en]!='?') en++;
            lens = lens-en+1;
            lenp = lenp-en+1;
            if (lens<st) return false;
            if (lenp<st) return false;

   //         cout << st << " " << en << " " << lens << " " << lenp << endl;
            vector<vector<bool> > flag;
            vector<vector<bool> >().swap(flag);

            vector<bool> tmp;
            vector<bool>().swap(tmp);

            tmp.push_back(true);
            for (int j=st;j<lenp;j++)
              if (p[j]=='*')
                tmp.push_back(true);
              else
              {
                  int k = j;
                  while (k<lenp)
                  {
                      tmp.push_back(false);
                      k++;
                  }
                  break;
              }
            flag.push_back(tmp);

            for (int i=st;i<lens;i++)
            {
                bool pd = false;
                flag.push_back(tmp);

                int x = i-st;
                if (flag[x][0] && s[i]=='*')
                  flag[x+1][0] = true;
                else
                  flag[x+1][0] = false;
                for (int j=st;j<lenp;j++)
                {
                    int y = j-st;
                    if (charMatch(s[i], p[j]) && flag[x][y])
                    {
                        flag[x+1][y+1] = true;
                        pd = true;
                    }
                    else
                      if (flag[x+1][y] && (s[i]=='*' || p[j]=='*'))
                      {
                          flag[x+1][y+1] = true;
                          pd = true;
                      }
                      else
                        if (flag[x][y+1] && (s[i]=='*' || p[j]=='*'))
                        {
                            flag[x+1][y+1] = true;
                            pd = true;
                        }
                        else
                        {   
                            flag[x+1][y+1] = false;
                        }
                }
                if (pd==false)
                  return false;
            }         
/*            for (int i=0;i<flag.size();i++)
            {
                for (int j=0;j<flag[i].size();j++)
                  cout << flag[i][j] << " ";
                cout<<endl;
            } */
            return flag[lens-st][lenp-st];
        }
};

int main()
{
    Solution s;
    cout << s.isMatch("aa", "aaaa") << endl;

} 
