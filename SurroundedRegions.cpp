/*************************************************************************
Author: HongYihong
Created Time: Fri 03 May 2013 05:23:46 PM CST
File Name: Work/code/leetcode/SurroundedRegions.cpp
Description: dfs->RE bfs->AC
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
        //        const int fx[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        //        void DFS(int x, int y, int n, int m, vector<vector<char> > &board)
        //        {
        //            for (int i = 0; i < 4; i++)
        //            {
        //                int nx = x + fx[i][0];
        //                int ny = y + fx[i][1];
        //                if (nx >=0 && nx < n && ny >= 0 && ny < m && board[nx][ny]=='O')
        //                {
        //                    board[nx][ny] = 'N';
        //                    DFS(nx, ny, n, m, board);
        //                }
        //            }
        //        }
        //        void solve(vector<vector<char> > &board) {
        //            // Start typing your C/C++ solution below
        //            // DO NOT write int main() function
        //
        //            int n, m = 0;
        //            n = board.size();
        //            if (n > 0)
        //              m = board[0].size();
        //
        //            for (int i = 0; i < n; i++)
        //            {
        //                if (board[i][0]=='O')
        //                {
        //                    board[i][0] = 'N';
        //                    DFS(i, 0, n, m, board);
        //                }                                
        //                if (board[i][m-1]=='O')
        //                {
        //                    board[i][m-1] = 'N';
        //                    DFS(i, m-1, n, m, board);
        //                }
        //            }
        //            for (int i = 0; i < m; i++)
        //            {
        //                if (board[0][i]=='O')
        //                {
        //                    board[0][i] = 'N';
        //                    DFS(0, i, n, m, board);
        //                }                                
        //                if (board[n-1][i]=='O')
        //                {
        //                    board[n-1][i] = 'N';
        //                    DFS(n-1, i, n, m, board);
        //                }
        //            }
        //            for (int i = 0; i < n; i++)
        //              for (int j = 0; j < m; j++)
        //                if (board[i][j]=='O')
        //                  board[i][j] = 'X';
        //                else
        //                  if (board[i][j]=='N')
        //                    board[i][j] = 'O';
        //            
        //            for (int i = 0; i < n; i++)
        //            {
        //                for (int j = 0; j < m; j++)
        //                  cout << board[i][j];
        //                cout << endl;
        //            }
        //
        //        }
        void solve(vector<vector<char> > &board) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function 

            const int fx[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
            int n, m = 0;
            n = board.size();
            if (n > 0)
              m = board[0].size();
            else
              return;
            vector<int> bfsx, bfsy;
            vector<int>().swap(bfsx);
            vector<int>().swap(bfsy);
            for (int i = 0; i < n; i++)
            {
                if (board[i][0]=='O')                                        
                {
                    board[i][0] = 'N';
                    bfsx.push_back(i);
                    bfsy.push_back(0);
                }
                if (board[i][m-1]=='O')                                        
                {
                    board[i][m-1] = 'N';
                    bfsx.push_back(i);
                    bfsy.push_back(m-1);
                }               
            }
            for (int i = 0; i < m; i++)
            {
                if (board[0][i]=='O')                                        
                {
                    board[0][i] = 'N';
                    bfsx.push_back(0);
                    bfsy.push_back(i);
                }
                if (board[n-1][i]=='O')                                        
                {
                    board[n-1][i] = 'N';
                    bfsx.push_back(n-1);
                    bfsy.push_back(i);
                }               
            }

            int st = 0, en = bfsx.size();
            while (st<en)
            {
                for (int i = 0; i < 4; i++)
                {
                    int nx = bfsx[st] + fx[i][0];
                    int ny = bfsy[st] + fx[i][1];
                    if (nx >=0 && nx < n && ny >= 0 && ny < m && board[nx][ny]=='O')
                    {
                        board[nx][ny] = 'N'; 
                        bfsx.push_back(nx);
                        bfsy.push_back(ny);
                        en++;
                    }
                }
                st++;
            }
            for (int i = 0; i < n; i++)
              for (int j = 0; j < m; j++)
                if (board[i][j]=='O')
                  board[i][j] = 'X';
                else
                  if (board[i][j]=='N')
                    board[i][j] = 'O';
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                  cout << board[i][j];
                cout << endl;
            }  
        }
};

int main()
{
    Solution s;
    vector<vector<char> > b;
    vector<char> bb;
    vector<char>().swap(bb);
    for (int i = 0; i<4;i++)
      bb.push_back('X');
    vector<char> bbb;
    vector<char>().swap(bbb);
    for (int i = 0; i<4;i++)
      bbb.push_back('O');

    for (int i = 0; i<4;i++)
      //    if (i%2==1)
      b.push_back(bbb);
    //  else
    //  b.push_back(bbb);  
      for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                  cout << b[i][j];
                cout << endl;
            }  
    s.solve(b);
    return 0;
}
