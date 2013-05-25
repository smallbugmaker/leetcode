/*************************************************************************
Author: HongYihong
Created Time: Fri 01 Mar 2013 05:59:52 PM CST
File Name: Code/code/leetcode/DistinctSubsequences.cpp
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
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (S.length()==0) return 0;
        if (T.length()==0) return 1;
        vector<vector<int> > rec, sum;
        vector<vector<int> >().swap(rec);
        vector<vector<int> >().swap(sum);

        vector<int> rectmp, sumtmp;
        vector<int>().swap(rectmp);
        vector<int>().swap(sumtmp);
        for (int j = 0; j < S.length(); j++)
        {
          if (T[0] == S[j])
            rectmp.push_back(1);
          else
            rectmp.push_back(0);
          if (j==0)
            sumtmp.push_back(rectmp[j]);
          else
            sumtmp.push_back(rectmp[j]+sumtmp[j-1]);
        }
        rec.push_back(rectmp);
        sum.push_back(sumtmp);

        for (int i = 1; i < T.length(); i++)
        {
            vector<int>().swap(rectmp);
            vector<int>().swap(sumtmp);
            for (int j = 0; j < S.length(); j++)
            {
                if (j < i)
                {
                  rectmp.push_back(0);
                  sumtmp.push_back(0);
                }
                else
                {
                    if (T[i] == S[j])
                        rectmp.push_back(sum[i-1][j-1]);
                    else
                      rectmp.push_back(0);
                    sumtmp.push_back(sumtmp[j-1]+rectmp[j]);
                }
            }
            rec.push_back(rectmp);
            sum.push_back(sumtmp);
        }
        return sum[T.length()-1][S.length()-1];
    }
};

int main()
{
    Solution s;
    cout << s.numDistinct("raabbbit","rabbit") << endl;
    return 0;
}
