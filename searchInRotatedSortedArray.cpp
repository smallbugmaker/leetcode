/*************************************************************************
Author: HongYihong
Created Time: Tue 26 Feb 2013 04:49:39 PM CST
File Name: Code/code/leetcode/searchInRotatedSortedArray.cpp
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
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int s = 0, e = n-1;
        while (s<=e)
        {
            int m = (s+e)/2;
            cout << s << '\t' << m << '\t' << e << endl;
            cout << A[s] << '\t' << A[m] << '\t' << A[e] << endl << endl;
            if (A[s]==target) return s;
            if (A[e]==target) return e;
            if (A[m]==target) return m;
            if (target > A[s])
              if (target > A[m])
                if (A[s] >= A[m]) e = m-1;
                else
                  s = m+1;
              else
                e = m-1;
            else
              if (target > A[m]) s = m+1;
              else
                if (A[s] >= A[m]) e = m-1;
                else
                  s = m+1;
        }
        return -1;
    }
};

int main()
{
//    int A[10] = {4,5,6,7,8,9,0,1,2,3};
    int A[10] = {7,8,9,0,1,2,3,4,5,6};
    Solution s;
    int n;
    cin >> n;
    cout << s.search(A, 10, n) << endl;
    return 0;
}
