/*************************************************************************
Author: h.yihong.cs
Created Time: 2013/2/28 19:25:34
File Name: stringtoInteger.cpp
Description: 
 ************************************************************************/
#include <iostream>
#include <cstring>
using namespace std;
#define out(x) (cout<<#x<<": "<<x<<endl)
const int maxint=0x7FFFFFFF;
typedef long long int64;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template<class T>void show(T a, int n){for(int i=0; i<n; ++i) cout<<a[i]<<' '; cout<<endl;}
template<class T>void show(T a, int r, int l){for(int i=0; i<r; ++i)show(a[i],l);cout<<endl;}

class Solution {
    public:
	int atoi(const char *str) {
	    // Start typing your C/C++ solution below
	    // DO NOT write int main() function

	    int end = strlen(str)-1;
	    int start = 0;
	    while (start<=end && str[start]==' ') start++;
	    while (end>=0 && str[end]==' ') end--;

	    for (int i = start; i <= end; i++)
	    {
		if (str[i] >= '0' && str[i] <= '9') continue;
		if (str[i]=='-' && i==start) continue;
		if (str[i]=='+' && i==start) continue;
		end = i-1;
		break;
	    }

	    if (end<start) return 0;

	    cout << start << ' ' << end << endl;
	    int res = 0;
	    if (str[start]=='-')
	    {
		if (end-start+1>11) return -2147483648;
		if (end-start+1==11 && str[start+1]>'3') return -2147483648;
		long long r = 0;
		for (int i=start+1; i<=end; i++)
		    r = r*10 - (str[i]-'0');
		cout << r << endl;
		if (r>=-2147483647)
		    return (int) r;
		else
    		    return -2147483648;
	    }
	    else
	    {
		int s = 10;
		if (str[start]=='+')
		    s = 11;
		if (end-start+1>s) return 2147483647;
		if (end-start+1==s && str[start+s-10]>'3') return 2147483647;
		long long r = 0;
		for (int i=start+s-10; i<=end; i++)
		    r = r*10 + (str[i]-'0');
		if (r>2147283647)
		    return 2147483647;
		return (int)r;
	    }
	}
};

int main()
{
    Solution s;
    cout << s.atoi("     -11111 ") << endl;
    return 0;
}

