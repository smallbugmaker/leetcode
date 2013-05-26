/*************************************************************************
Author: HongYihong
Created Time: Sun 26 May 2013 02:36:01 PM CST
File Name: UniqueBinarySearchTrees2.cpp
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
        vector<TreeNode *> getTrees(int st, int en)
        {   
            vector<TreeNode *> res;
            vector<TreeNode *>().swap(res);
            if (st>en)
            {
                res.push_back(NULL);
                return res;
            }
            for (int i=st; i<=en; i++)
            {
                vector<TreeNode *> leftTree;
                vector<TreeNode *>().swap(leftTree);

                vector<TreeNode *> rightTree;
                vector<TreeNode *>().swap(rightTree);

                leftTree = getTrees(st, i-1);
                rightTree = getTrees(i+1, en);

                for (int j=0; j<leftTree.size(); j++)
                {
                    for (int k=0; k<rightTree.size(); k++)
                    {
                        TreeNode *root = new TreeNode(i);                        
                        root->left = leftTree[j];
                        root->right = rightTree[k];
                        res.push_back(root);
                    }

                }
            }
            return res;
        }

        vector<TreeNode *> generateTrees(int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<TreeNode *> res;
            vector<TreeNode *>().swap(res);
            res = getTrees(1, n);

            return res;
        }
};

int main()
{
    Solution s;
    s.generateTrees(3);
}
