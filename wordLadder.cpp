/*************************************************************************
Author: h.yihong.cs
Created Time: 2013/3/7 19:56:28
File Name: wordLadder.cpp
Description: TLE
 ************************************************************************/
#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        int ladderLength(string start, string end, unordered_set<string> &dict) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function

            if (dict.size()==0) return 0;
            if (start.length()!=end.length()) return 0;
            if (start.length()==0 || end.length()==0) return 0;
            
            queue<string> in, out;
            out.push(start);

            int dis = 1;

            while (dict.size()>0 && out.size()>0)
            {
                queue<string>().swap(in);
                while (!out.empty())
                {
                    string now(out.front());
                    out.pop();
                    for (int i=0; i<now.length(); i++)
                    {
                        char c = now[i];
                        for (int j='a'; j<='z'; j++)
                          if (c!=j)
                          {
                              now[i] = j;
                              if (end==now)
                                return dis+1;
                              if (dict.find(now)!=dict.end())
                              {
                                  in.push(now);
                                  dict.erase(now);
                              }
                              now[i] = c;
                          }
                    }
                }
                swap(in,out);
                dis++;
            }
            return 0;
        }
};
