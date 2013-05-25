/*************************************************************************
Author: HongYihong
Created Time: Thu 28 Feb 2013 11:22:51 AM CST
File Name: Code/code/leetcode/BestTimetoBuyandSellStock2.cpp
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
            int maxp = 0;
            int i = 0;
            while (i < prices.size())
            {
                int j = i;
                while (j+1 < prices.size() && prices[j+1] > prices[j])
                  j++;
                maxp += prices[j] - prices[i];
                i = j+1;
            }
            return maxp;
        }
};

int main()
{
    Solution s;
    vector<int> a;
    vector<int>().swap(a);
    a.push_back(1);
    a.push_back(4);
    a.push_back(2);
    cout << s.maxProfit(a) << endl;
}
