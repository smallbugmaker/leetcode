/*************************************************************************
Author: HongYihong
Created Time: Thu 28 Feb 2013 03:17:24 PM CST
File Name: Code/code/leetcode/BestTimetoBuyandSellStock3.cpp
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
        int maxProfit(vector<int> &prices) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if (prices.size()==0) return 0;
            int n = prices.size();

            vector<int> max0;
            vector<int>().swap(max0);
            max0.push_back(0);
            int minp = prices[0];

            for (int i = 1; i < n; i++)
            {
                if (prices[i] < minp)
                  minp = prices[i];
                if (prices[i] - minp > max0[i - 1])
                  max0.push_back(prices[i] - minp);
                else
                  max0.push_back(max0[i - 1]);
            }

            int maxp = prices[n-1];
            int m = 0, res = max0[n - 1];
            for (int i = n - 2; i > 0; i--)
            {
                if (prices[i] > maxp)
                  maxp = prices[i];
                if (maxp - prices[i] > m)
                  m = maxp - prices[i];
                if (m + max0[i-1] > res)
                  res = m + max0[i-1];
            }
            return res;
        }
};

int main()
{
    Solution s;
    vector<int> a;
    vector<int>().swap(a);
    a.push_back(2);
    a.push_back(1);
    a.push_back(2);  
    a.push_back(0);
    a.push_back(1);
    cout << s.maxProfit(a) << endl;
}
