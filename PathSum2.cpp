/*************************************************************************
Author: HongYihong
Created Time: Thu 23 May 2013 10:57:26 AM CST
File Name: Work/code/leetcode/PathSum2.cpp
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        void action(TreeNode *root, int sumNow, int &sum, vector< int > &vecNow, vector< vector< int > > & res)
        {
            if (root->left==NULL && root->right==NULL)
            {
                if (sumNow==sum)
                {
                    res.push_back(vecNow);
                }
                return ;
            }

            if (root->left!=NULL)
            {
                vecNow.push_back(root->left->val);
                action(root->left, sumNow+root->left->val, sum, vecNow, res);
                vecNow.pop_back();
            }

            if (root->right!=NULL)
            {       
                vecNow.push_back(root->right->val);
                action(root->right, sumNow+root->right->val, sum, vecNow, res);
                vecNow.pop_back();
            }            
        }   
        vector<vector<int> > pathSum(TreeNode *root, int sum) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int> vecNow;
            vector<int>().swap(vecNow);

            vector< vector<int> > res;
            vector< vector<int> >().swap(res);
            if (root==NULL) return res;

            vecNow.push_back(root->val);
            action(root, root->val, sum, vecNow, res);

           /* for (int i = 0; i<res.size(); i++)
            {
                for (int j = 0; j<res[i].size(); j++)
                  cout << res[i][j] << " " <<endl;
                cout << endl;
            }*/
            return res;
        }
};

int main()
{
    TreeNode *a = new TreeNode(-2);
    TreeNode *b = new TreeNode(-3);
    
    a->right = b;

    Solution s;
    s.pathSum(a, -2);
    return 0;
}
