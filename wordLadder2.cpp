/*************************************************************************
Author: HongYihong
Created Time: Thu 23 May 2013 03:25:41 PM CST
File Name: Work/code/leetcode/wordLadder2.cpp
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
#include <unordered_set>
using namespace std;

//MLE

class Solution {
    public:    
    
    struct nodes
    {
        string s;
        int dist;
        int from;
        nodes(string ss, int d, int f): s(ss), dist(d), from(f) {}                
    };
    
    void findresult(vector<nodes> &q, vector<vector<string> > &res)
    {
        vector<string> p;
        vector<string>().swap(p);
        int x = q.size()-1;
        while (x!=-1)
        {
            p.insert(p.begin(), q[x].s);
            x = q[x].from;
        }      
        res.push_back(p);
    }
    
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            //

            vector< vector<string> > res;
            vector< vector<string> >().swap(res);
            if (dict.size()==0) return res;
            if (start.length()!=end.length()) return res;
            if (start.length()==0 || end.length()==0) return res;            

            vector<nodes> q;
            vector<nodes>().swap(q);
            nodes first(start, 1, -1);
            q.push_back(first);
            
            int st = 0, en = 0, mindist = dict.size()+100, dist = 1;
            
            while (st<=en)
            {
                if (q[st].dist>=mindist)
                {
                    st++;
                    continue;
                }
                string s(q[st].s);
                for (int i=0; i<s.length(); i++)
                {
                    char c = s[i];
                    for (int j='a'; j<='z'; j++)
                    if (c!=j)
                    {
                        s[i] = j;                        
                        if (dict.find(s)!=dict.end())
                        {   
                            if (q[st].from!=-1 && s==q[q[st].from].s) continue;
                            nodes now(s, q[st].dist+1, st);
                            q.push_back(now);
                            if (end==s)
                            {
                                mindist = q[st].dist+1;
                                findresult(q, res);
                                q.pop_back();
                            }
                            else
                                en++;
                        }                        
                    }
                    s[i] = c; 
                }
                st++;                
            }

            return res;
        }
};


//TLE
class Solution {
    public:  
    
    int mindist;
    void find(string s, string end, vector< vector<string> > &res, vector<string> &now, unordered_set<string> &dict)
    {
        int t = now.size();
        if (t>mindist) return;        
        if (s==end)
        {
            if (t<mindist)
            {
                vector<vector<string> >().swap(res);
                mindist = t;
            }
            res.push_back(now);
            return;
        }
        for (int i=0; i<s.length(); i++)
        {
            char c = s[i];
            for (int j='a'; j<='z'; j++)
            {
                if (c!=j)
                {
                    s[i] = j;
                    if (dict.find(s)!=dict.end())
                    {
                        now.push_back(s);
                        dict.erase(s);
                        find(s, end, res, now, dict);
                        now.pop_back();
                        dict.insert(s);
                    }
                    s[i] = c;
                }
            }
        }
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            //

            vector< vector<string> > res;
            vector< vector<string> >().swap(res);
            if (dict.size()==0) return res;
            if (start.length()!=end.length()) return res;
            if (start.length()==0 || end.length()==0) return res;            

            vector<string> now;
            vector<string>().swap(now);
            now.push_back(start);            

            mindist = dict.size()+1;

            find(start, end, res, now, dict);
            return res;
        }
};  
