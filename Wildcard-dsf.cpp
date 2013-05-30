/*************************************************************************
TLE
Author: HongYihong
Created Time: Mon 17 Dec 2012 10:56:26 PM CST
File Name: Code/code/Wildcard.cpp
Description:                    TLE
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

    bool action(const char *s, const char *p)
    {
   /*     cout << s << endl;
        cout << p << ":" <<strlen(p) << endl;
        getchar();*/

        if (strlen(p)==1 && p[0]=='*') return true;
        if (strlen(s)==0)
        {
            if (strlen(p)==0) return true;
            return false;
        }
        if (strlen(p)==0) return false;
        if ((s[0]==p[0]) || (p[0]=='?'))
            return action(s+1, p+1);

        if (p[0]=='*')
        {
            for (int i=0;i<strlen(s);i++)
            {
                if (action(s+i, p+1))
                  return true;
            }
        }
        return false;
    }

    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //
   //     cout << p << endl;
        char sp[1024];
        int j=0;

        char np[1024];
        int k = 0;
        const char *ns = s;
      //  cout << ns << endl;
        
        for (int i=0;i<strlen(p);i++)
        {
            if (i>=0 && p[i]=='*' && p[i]==p[i-1])
              continue;             
            if (p[i]=='*' || p[i]=='?')
            {
                np[k] = '\0';
                const char *res = strstr(ns, np);
                if (res==NULL) return false;
                //if (strstr(ns,np)==NULL) return false;
                ns = res+k;
            //    cout << "1: " << np << endl;
             //   cout << "2: " << ns << endl;
                np[0] = '\0';
                k = 0;
            }
            else
            {
                np[k] = p[i];
                k++;
            }
            sp[j] = p[i];
            j++;
        }       
        np[k] = '\0';
        if (strstr(ns, np)==NULL) return false;
        sp[j] = '\0';

        char tmp1[1024];
        j = 0;
        for (int i=strlen(s)-1;i>=0;i--){
            tmp1[j] = s[i]; j++;
        }
        tmp1[j] = '\0';
        char *rs = tmp1;

        char tmp2[1024];
        j = 0;
        for (int i=strlen(sp)-1;i>=0;i--){
            tmp2[j] = sp[i]; j++;
        }
        tmp2[j]='\0';
        char *rp = tmp2;
        cout << s << endl;
        cout << rs << endl;
        cout << sp << endl;
        cout << rp << endl;
        k = 0;
        for (int i=0;i<strlen(rp);i++)
            if (rp[i]=='*' || rp[i]=='?')
            {
                np[k] = '\0';
                char *res = strstr(rs, np);
                if (res==NULL) return false;
                //if (strstr(ns,np)==NULL) return false;
                rs = res+k;
         //       cout << "1: " << np << endl;
         //       cout << "2: " << rs << endl;
                np[0] = '\0';
                k = 0;
            }
            else
            {
                np[k] = rp[i];
                k++;
            }
        np[k] = '\0';
        cout << "np = " << np << endl;
        if (strstr(rs, np)==NULL) return false;
        cout << "ok" << endl;
        return action(s, sp);
    }
};

int main()
{
    Solution s;          
    cout << s.isMatch("aa", "a") << endl;
    cout << s.isMatch("aa", "aa") << endl;
    cout << s.isMatch("aaa", "aa") << endl;
    cout << s.isMatch("aa", "*") << endl;
    cout << s.isMatch("aa", "a*") << endl;
    cout << s.isMatch("ab", "?*") << endl;
    cout << s.isMatch("aab", "c*a*b") << endl;
    cout << s.isMatch("baaabbabbbaabbbbbbabbbaaabbaabbbbbaaaabbbbbabaaaaabbabbaabaaababaabaaabaaaabbabbbaabbbbbaababbbabaaabaabaaabbbaababaaabaaabaaaabbabaabbbabababbbbabbaaababbabbaabbaabbbbabaaabbababbabababbaabaabbaaabbba", "*b*ab*bb***abba*a**ab***b*aaa*a*b****a*b*bb**b**ab*ba**bb*bb*baab****bab*bbb**a*a*aab*b****b**ba**abba") << endl;
    cout << s.isMatch("babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb", "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a") << endl;
    cout << s.isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb") << endl;
    cout << s.isMatch("abbaabbbbababaababababbabbbaaaabbbbaaabbbabaabbbbbabbbbabbabbaaabaaaabbbbbbaaabbabbbbababbbaaabbabbabb", "***b**a*a*b***b*a*b*bbb**baa*bba**b**bb***b*a*aab*a**") << endl;
    cout << s.isMatch("abbbabaaabbabbabbabaabbbaabaaaabbbabaaabbbbbaaababbb", "**a*b*aa***b***bbb*ba*a") << endl;

} 
