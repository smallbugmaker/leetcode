/*************************************************************************
Author: HongYihong
Created Time: Tue 11 Dec 2012 04:40:53 PM CST
File Name: ZigZag.cpp
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

class Solution
{
    public:
        string convert(string s, int nRows)
        {
            if (nRows==1)
              return s;
            string s_ans = "";
            int len = s.length();
            int l = nRows*2-2;
            for (int i=0;i<nRows;i++)
            {
                int x = l-2*i;
                int z = i;
                while (z<len)
                {
                    if (x>0)
                    {
                        cout << z << " ";
                        s_ans +=s[z];
                        z = z+x;
                    }
                    x = l-x;
                }
            }
            return s_ans;
        }
};

int main()
{
    Solution s;
    cout << s.convert("PALL", 1) << endl;
}
