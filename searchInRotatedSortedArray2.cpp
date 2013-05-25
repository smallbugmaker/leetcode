/*************************************************************************
Author: HongYihong
Created Time: Tue 26 Feb 2013 05:15:43 PM CST
File Name: Code/code/leetcode/searchInRotatedSortedArray2.cpp
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
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int s = 0, e = n-1;
        while (s<=e)
        {
            int m = (s+e)/2;
            cout << s << '\t' << m << '\t' << e << endl;
            cout << A[s] << '\t' << A[m] << '\t' << A[e] << endl << endl;
            if (A[s]==target) return true;
            if (A[e]==target) return true;
            if (A[m]==target) return true;
            if (target > A[s])
              if (target > A[m])
                if (A[s] > A[m]) e = m-1;
                else
                  if (A[s] == A[m])
                  {
                      if (A[s] == A[e])
                      {
                          s = s+1;
                          e = e-1;
                      }
                      else
                        s = m+1;
                  }
                  else
                    s = m+1;
              else
                e = m-1;
            else
              if (target > A[m]) s = m+1;
              else
                if (A[s] > A[m]) e = m-1;
                else
                  if (A[s] == A[m])
                  {
                      if (A[s] == A[e])
                      {
                          s = s+1;
                          e = e-1;
                      }
                      else
                        s = m+1;
                  }
                  else
                    s = m+1;
        }
        return false;
    }
};

int main()
{
//    int A[10] = {0,1,2,3,4,5,6,7,8,9};
    int A[5] = {3,3,3,1,3};
    Solution s;
    int n;
    cin >> n;

    cout << s.search(A, 5, n) << endl;
    return 0;
}
