/*************************************************************************
Author: h.yihong.cs
Created Time: 2013/2/20 21:58:04
File Name: nQueen.cpp
Description: 
************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

void dfs(vector<vector<string> > & ans, vector<string> & anstemp, int n, long long ex, long long r, long long ld, long long rd)
{
    if (r==ex)
    {
	ans.push_back(anstemp);
	for (int i = 0; i < n; i++)
	    cout << anstemp[i] << endl;
    }
    else
    {
	//long long ypos = ~(r | ld | rd);
	long long ypos = ex & ( ~(r | ld | rd) );
	while (ypos)
	{
	    //long long pos = ypos & (~ypos+1);
	    long long pos = ypos & (-ypos);
	    anstemp[n][(int)log2((double)pos)] = 'Q';
	    ypos = ypos - pos;
	    dfs(ans, anstemp, n+1, ex, r+pos, (ld+pos)<<1, (rd+pos)>>1);
	    anstemp[n][(int)log2((double)pos)] = '.';
	}
    }
}
vector<vector<string> > solveNQueens(int n){
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
     char s[100];
     for (int i = 0; i < n; i++)
	 s[i] = '.';
     s[n] = '\0';
     //cout << s << endl;
     string ss(s);
     vector<string> anstemp;
     vector<string>().swap(anstemp);
     vector< vector<string> > ans;
     vector< vector<string> >().swap(ans);
     for (int i = 0; i < n; i++)
	 anstemp.push_back(ss);
     dfs(ans, anstemp, 0, (1<<n)-1, 0, 0, 0);
     return ans;
}

int main()
{
    int n;
    cin >> n;
    solveNQueens(n);
    return 0;
}

