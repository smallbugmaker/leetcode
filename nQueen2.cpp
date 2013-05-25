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

void dfs(int &sum, long long ex, long long r, long long ld, long long rd)
{
    if (r==ex)
    {
	sum ++;
    }
    else
    {
	//long long ypos = ~(r | ld | rd);
	long long ypos = ex & ( ~(r | ld | rd) );
	while (ypos)
	{
	    //long long pos = ypos & (~ypos+1);
	    long long pos = ypos & (-ypos);
	    ypos = ypos - pos;
	    dfs(sum, ex, r+pos, (ld+pos)<<1, (rd+pos)>>1);
	}
    }
}
int totalNQueens(int n){
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
     int sum = 0;
     dfs(sum, (1<<n)-1, 0, 0, 0);
     return sum;
}

int main()
{
    int n;
    cin >> n;
    cout << totalNQueens(n) << endl;
    return 0;
}

