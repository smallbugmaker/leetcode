/*************************************************************************
Author: HongYihong
Created Time: Sun 24 Feb 2013 04:00:11 PM CST
File Name: Code/code/InsertIntervals.cpp
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

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

class Solution {
public:
    static bool cmp(const Interval &x, const Interval &y)
    {
        return x.start < y.start;
    }
    
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), cmp);
 /*       vector<Interval> res;
        vector<Interval>().swap(res);
        int i = 0;
        while (i != intervals.size())
        {
            Interval tmp(intervals[i].start, intervals[i].end);
            while (i < intervals.size()  && tmp.end > intervals[i].start)
            {
                if (tmp.end < intervals[i].end)
                  tmp.end = intervals[i].end;
                i++;
            }
            res.push_back(tmp);
        }*/       
        int i = 0;
        while (i != intervals.size())
        {
            while (i+1 < intervals.size()  && intervals[i].end >= intervals[i+1].start)
            {
                if (intervals[i].end < intervals[i+1].end)
                  intervals[i].end = intervals[i+1].end;
                intervals.erase(intervals.begin()+i+1);
            }
            i++;
        }
        for (int i=0;i<intervals.size();i++)
          cout << intervals[i].start << " " << intervals[i].end << endl;
        return intervals;
    }
};

int main()
{
    Solution s;
    vector<Interval> vec;
    vector<Interval>().swap(vec);
    Interval i;
    i.start = 1; i.end = 2;
    vec.push_back(i);
    i.start = 2; i.end = 6;
    vec.push_back(i);
    i.start = 7; i.end = 10;
    vec.push_back(i);
    i.start = 15; i.end = 18;
    vec.push_back(i);

    s.merge(vec);
    return 0;
}
