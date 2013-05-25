/*************************************************************************
Author: h.yihong.cs
Created Time: 2013/2/28 20:31:42
File Name: validNumber.cpp
Description: 
************************************************************************/
#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
    bool isnum(char c)
    {
	if (c>='0' && c<='9')
	    return true;
	return false;
    }
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	int start = 0;
	int end = strlen(s)-1;
	while (start<end && s[start]==' ') start++;
	while (end>=0 && s[end]==' ') end--;
//	cout << start << " " << end << endl; 
	if (end<start) return false;

//	cout << s << endl;
	bool dotf = true, ef = true;
        for (int i= start; i<=end; i++)
	{
//	    cout << s[i] << endl;
	    if (isnum(s[i])) continue;
	    if (s[i]=='+' || s[i]=='-')
	    {
		if (i==end) return false;
		if (ef)
		{
    		    if (i!=start) return false;
		    if (i<end && s[i+1]=='e') return false;
		}
		else
		{
		    if (s[i-1]!='e') return false;
		}
		continue;
	    }
	    if (s[i]=='.' && ef && dotf)
	    {
		dotf = false;
		if ( (i>start && isnum(s[i-1]) || (i<end && isnum(s[i+1])) ))			continue;
	    }
	    if (s[i]=='e' && i!=start && i!=end && ef)
	    {
		ef = false;
		continue;
//		if ( (i>start && isnum(s[i-1]) || (i<end && isnum(s[i+1])) ))			continue;
	    }
	    return false;
	}
	return true;
    }
};


int main()
{
    Solution S;
    cout << S.isNumber(" ") << endl;
    cout << S.isNumber("0") << endl;
    cout << S.isNumber(" 0.1") << endl;
    cout << S.isNumber("1 a") << endl;
    cout << S.isNumber("2e10") << endl;
    return 0;
}

