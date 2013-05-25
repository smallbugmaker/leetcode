/*************************************************************************
Author: HongYihong
Created Time: Sun 24 Mar 2013 10:59:36 PM CST
File Name: Code/code/leetcode/LongestConsecutiveSequence.cpp
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
        int longestConsecutive(vector<int> &num) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            unordered_map<int, int> st, en;    //index, length, tot
            unordered_map<int, int>().swap(st); 
            unordered_map<int, int>().swap(en);

            int res = 0;        
            for (int i = 0; i < num.size(); i++)
            {         
                int n = num[i];
                if (st.find(n) != st.end()) continue;
                int flag = 0;

                if (st.find(n+1) != st.end())
                {
                    st.insert(make_pair(n, st[n+1]+1));
                    en[n+st[n+1]] +=1;
                    if (en[n+st[n+1]] >res)
                      res = en[n+st[n+1]];
                    flag++;
                }
                else
                {
                    st.insert(make_pair(n, 1));
                }                

                if (en.find(n-1) != en.end())
                {
                    en.insert(make_pair(n, en[n-1]+1));
                    st[n-en[n-1]] +=1;
                    if (st[n-en[n-1]]>res)
                      res = st[n-en[n-1]];
                    flag++;
                }
                else
                {
                    en.insert(make_pair(n, 1));
                }
                if ( st[n] > res )
                  res = st[n];
                if ( en[n] > res )
                  res = en[n];

                if (flag == 2)
                {
                    st[n - en[n] + 1] += st[n] - 1;
                    if (st[n - en[n] + 1] > res)
                      res = st[n - en[n] + 1];

                    en[n + st[n] - 1] += en[n] -1;
                    if (en[n + st[n] - 1] > res)
                      res = en[n + st[n] - 1];
                }

                /*     for (map<int, int>::iterator itr = st.begin(); itr!=st.end(); itr++)
                       cout << itr->first << ": " << itr->second << " ";
                       cout << endl;
                       for (map<int, int>::iterator itr = en.begin(); itr!=en.end(); itr++)
                       cout << itr->first << ": " << itr->second << " ";
                       cout << endl;*/

            }
            return res;
        }
};

int main()
{
    Solution s;
    vector<int> num;
    vector<int>().swap(num);
    num.push_back(-1);
    num.push_back(1);
    num.push_back(0);
    cout << s.longestConsecutive(num) << endl;
}
