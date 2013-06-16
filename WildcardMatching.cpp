/*************************************************************************
Author: HongYihong
Created Time: Thu 13 Jun 2013 02:08:46 PM CST
File Name: WildcardMatching.cpp
Description:  TLETLETLE
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
/*class Solution {
public:
    const char *predo(const char *p)
    {        
        string s = "";        
        for (int i=0; i<strlen(p); i++)
        {
            if (i>0 && p[i]=='*' && p[i-1]=='*') continue;
            s.push_back(p[i]);            
        }
        return s.c_str();
    }
    
    bool ismatch(const char *s, const char *p)
    {
        int sl = strlen(s), pl = strlen(p);
        if (sl==0)
        {
            if (pl==0) return true;
            for (int i=0; i<pl; i++)
                if (p[i]!='*') return false;
            return true;            
        }
        else
          if (pl==0) return false;
        
        bool flag = false;
        if (*p=='*')
            flag = ismatch(s, p+1) || ismatch(s+1,p);
        if (flag== false && (*s==*p || *p=='?'))
            return ismatch(s+1, p+1);
        
        return flag;
    }
    
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      return ismatch(s, predo(p));              
    }
};   */

class Solution {
public:
    void predo(vector<string> &ps, const char *p)
    {        
        string s = ""; 
        int i = 0, n = strlen(p);
        while (i<n)
        {
            if (p[i]=='*')
            {
                if (s.length()>0) ps.push_back(s);
                ps.push_back("*");
                while (i<n && p[i]=='*') i++;
                s = "";
            }
            else
                if (p[i]=='?')
                {
                    if (s.length()>0) ps.push_back(s);
                    ps.push_back("?");                
                    s = "";
                    i++;
                }
                else
                {
                    s.push_back(p[i]);            
                    i++;
                }
        } 
        if (s.length()>0) ps.push_back(s);
    }
    
     bool ismatch(const char *s, vector<string> &ps, int t, bool starflag)
    {   
        int lens = strlen(s);
        if (t==ps.size())
        { 
            if (lens==0) return true;
            return false;
        }
        
        
        if (lens==0)
        {
            if (t!=ps.size()-1) return false;
            if (ps[t]!="*")  return false;            
            return true;
        }
        
        if (ps[t]=="*")
        {
            if (t==ps.size()-1) return true;
            return ismatch(s, ps, t+1, true);
        }
        
        int len = ps[t].length();    
        
        if (!starflag)
        {
         
            if (ps[t]=="?")
            {
                return ismatch(s+1, ps, t+1, false);
            }
            if (lens<len) return false;
            for (int j=0; j<len; j++)
            {
                if (s[j]==ps[t][j]) continue;
                return false;                
            }            
            return ismatch(s+len, ps, t+1, false);
        }
        else
        {            
            bool flag = false;
            if (ps[t]=="?")
            {
                for (int i=0; i<lens; i++)
                {
                    flag = ismatch(s+i+1, ps, t+1, false);
                    if (flag) break;
                }
            }
            else
            while (1)
            {
                const char *find = strstr(s, ps[t].c_str());
               // cout << find << endl;
                if (find==NULL) return false;
                flag = ismatch(find+len, ps, t+1, false);
                s = find+1;
                if (flag) break;                
            }
            return flag;
        }        
    } 
    
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (strlen(p)==0)
        {
            if (strlen(s)==0) return true;
            else
                return false;
        }
        
        vector<string> ps;
        vector<string>().swap(ps);
        
        predo(ps, p);        
        return ismatch(s, ps, 0, false);        
    }
}; 

int main()
{
    Solution s;
    cout << s.isMatch("bc","*?");
    return 0;
}
