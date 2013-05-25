/*************************************************************************
Author: HongYihong
Created Time: Thu 28 Feb 2013 11:22:51 AM CST
File Name: Code/code/leetcode/BestTimetoBuyandSellStock.cpp
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
        int minv = 2147483647, maxp = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minv)
              minv = prices[i];
            if (prices[i] - minv > maxp)
              maxp = prices[i] - minv;
        }
        return maxp;
    }
};

int main()
{
    Solution s;
}
