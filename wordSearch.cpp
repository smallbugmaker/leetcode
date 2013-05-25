/*************************************************************************
Author: HongYihong
Created Time: Sat 15 Dec 2012 05:11:03 PM CST
File Name: Code/code/wordSearch.cpp
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
    bool flag;
    vector<vector<bool> > yes;

    void action(vector<vector<char> > &board, string &word, int pos, int x, int y)
    {
        if (pos==word.length())
        {
            flag = true;
            return ;
        }

        int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        for (int i=0;i<4;i++)
        {
            int nx = x+fx[i][0];
            int ny = y+fx[i][1];
            if (nx>=0 && nx<board.size() && ny>=0 && ny<board[nx].size())
            {
                if (board[nx][ny]==word[pos])
                {
                    board[nx][ny] = '0';
                    action(board, word, pos+1, nx, ny);
                    board[nx][ny] = word[pos];
                }
            }
            if (flag) return ;
        }
    }

    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (word.length()==0)
          return 0;
        for (int i=0;i<board.size();i++)
          for (int j=0;j<board[i].size();j++)
            if (board[i][j]==word[0])
            {
                board[i][j] = '0';
                flag = false;
                action(board, word, 1, i, j);
                if (flag)
                  return true;
                board[i][j] = word[0];
            }
        return false;
    }
};

int main()
{
    Solution sl;
    string s = "AA";
    vector<vector<char> > board;
    int x = 0;
    for (int i=0;i<1;i++)
    {
        vector<char>tmp;
        vector<char>().swap(tmp);
        for (int j=0;j<2;j++)
        {
            tmp.push_back(s[x]);
            x++;
        }
        board.push_back(tmp);
    }
    
    cout << sl.exist(board, "AA") << endl;
}
