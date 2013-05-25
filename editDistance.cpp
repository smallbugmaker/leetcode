/*************************************************************************
Author: h.yihong.cs
Created Time: 2013/2/28 19:00:42
File Name: editDistance.cpp
Description: 
************************************************************************/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	vector<vector<int> > dis;
	vector<vector<int> >().swap(dis);
	int l1 = word1.length();
	int l2 = word2.length();

	for (int i=0; i<=l1;i++)
	{
    	    vector<int> temp;
    	    vector<int>().swap(temp);
    	    for (int j=0; j<=l2; j++)
	    {
		if (i==0)
 		    temp.push_back(j);
		else
		    temp.push_back(2147483647);
	    }
	    dis.push_back(temp);
	}

	for (int i=0; i<l1; i++)
	{
	    dis[i+1][0] = i+1;
	    for (int j=0; j<l2; j++)
	    {
		if (word1[i]==word2[j])
		{
		    dis[i+1][j+1] = dis[i][j];
		}
		if (dis[i][j]+1 < dis[i+1][j+1])
		    dis[i+1][j+1] = dis[i][j]+1;
		if (dis[i][j+1] + 1 < dis[i+1][j+1])
		    dis[i+1][j+1] = dis[i][j+1]+1;
		if (dis[i+1][j] + 1 < dis[i+1][j+1])
		    dis[i+1][j+1] = dis[i+1][j]+1;
	//	cout << dis[i+1][j+1] << " ";
	    }
	  //  cout << endl;
	}
	return dis[l1][l2];
    }
};

int main()
{
    Solution s;
    cout << s.minDistance("aaabb","aaaa") << endl;
    return 0;
}

