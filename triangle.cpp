/*************************************************************************
Author: HongYihong
Created Time: Wed 22 May 2013 07:51:49 PM CST
File Name: Work/code/leetcode/triangle.cpp
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
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int n = triangle.size();
        for (int i=n-2; i>=0; i--)
        {
            int m = triangle[i].size();
            for (int j=0; j<m; j++)
            {
                int x = triangle[i][j];
                triangle[i][j] = triangle[i+1][j]+x;
                if (triangle[i+1][j+1]+x < triangle[i][j])
                {
                    triangle[i][j] = triangle[i+1][j+1]+x;
                }        
            }
        }
        return triangle[0][0];
    }
};
