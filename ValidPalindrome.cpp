/*************************************************************************
Author: HongYihong
Created Time: Wed 22 May 2013 05:47:07 PM CST
File Name: Work/code/leetcode/ValidPalindrome.cpp
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
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string news = "";
        for (int i = 0; i < s.length(); i++)
          if (s[i] >= 'a' && s[i] <= 'z')
            news +=s[i];
          else
            if (s[i] >= 'A' && s[i] <= 'Z')
              news += 'a' + (s[i]-'A');
            else
              if (s[i] >= '0' && s[i] <= '9')
                news +=s[i];

        int len = news.length();
        for (int i = 0; i< len/2; i++)
          if (news[i] != news[len-i-1])
            return false;
        return true;
    }
};
