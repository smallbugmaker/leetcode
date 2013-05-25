/*************************************************************************
Author: HongYihong
Created Time: Thu 23 May 2013 03:25:41 PM CST
File Name: Work/code/leetcode/wordLadder2.cpp
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
#include <unordered_set>
using namespace std;

class Solution {
    public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            //

            vector< vector<string> > res;
            vector< vector<string> >().swap(res);
            if (dict.size()==0) return res;
            if (start.length()!=end.length()) return res;
            if (start.length()==0 || end.length()==0) return res;            

            queue< vector<string> > in, out;
            vector<string> temp;
            vector<string>().swap(temp);
            temp.push_back(start);
            out.push(temp);

            int dis = 1;
            int min = -1;

            while (out.size()>0)
            {
                queue< vector<string> >().swap(in);
                while (!out.empty())
                {
                    vector<string> now(out.front());
                    out.pop();
                    int n = now.size();
                    string s(now[n-1]);
                    for (int i=0; i<s.length(); i++)
                    {
                        
                        char c = s[i];
                        for (int j='a'; j<='z'; j++)
                          if (c!=j)
                          {
                              s[i] = j;
                             
                              if (dict.find(s)!=dict.end())
                              {
                                  in.push(now);
                                  in.back().push_back(s);
                              }
                              if (end==s)
                              {
                                  res.push_back(now);
                                  res[res.size()-1].push_back(end);
                                  min = dis+1;  
                              }
                              s[i] = c;
                          }
                    }
                }
                swap(in,out);
                dis++;
                if (dis>min && min!=-1) break;
            }

            return res;
        }
};
