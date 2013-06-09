/*************************************************************************
Author: HongYihong
Created Time: Fri 07 Jun 2013 05:28:49 PM CST
File Name: SudokuSolver.cpp
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
    bool row[9][9], col[9][9], grid[3][3][9];
    vector<pair<int, int> > points;
    
    bool solve(vector<vector<char> > &board, int pos, int num)
    {
        if (pos==num)     
            return true;
        int i = points[pos].first;
        int j = points[pos].second;
        for (int k=0; k<9; k++)
        {
            if (row[i][k]==false && col[j][k]==false && grid[i/3][j/3][k]==false)
            {
                char c = k+'1';
                board[i][j] = c;
                row[i][k] = true;
                col[j][k] = true;
                grid[i/3][j/3][k] = true;
                bool flag = solve(board, pos+1, num);                        
                if (flag)
                  return true;
                board[i][j] = '.';
                row[i][k] = false;
                col[j][k] = false;
                grid[i/3][j/3][k] = false;
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function                
 
        points.clear();
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(grid, false, sizeof(grid));        
        int num = 0;
        for (int i=0; i<9; i++)
        {
            for (int j=0; j<9; j++)
                if (board[i][j]!='.')
                {
                    row[i][board[i][j]-'1'] = true;
                    col[j][board[i][j]-'1'] = true;
                    grid[i/3][j/3][board[i][j]-'1'] = true;
                }
                else
                {
                    points.push_back(make_pair(i,j));
                    num++;
                }
        }
        solve(board, 0, num);             
    }
};

int main()
{
//    string s[9] = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
    string s[9] = {"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};
    vector<vector<char> > board;
    for (int i=0; i<9; i++)
    {
        vector<char> tmp;
        vector<char>().swap(tmp);
        for (int j=0; j<9; j++)
          tmp.push_back(s[i][j]);
        board.push_back(tmp);
    }
    Solution solu;
    solu.solveSudoku(board);
}
