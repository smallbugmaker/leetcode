/*************************************************************************
Author: HongYihong
Created Time: Wed 22 May 2013 05:19:34 PM CST
File Name: sumroot2leafnumber.cpp
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
        void calcsum(TreeNode *node, int now, int &sum)
        {
            if (node->left==NULL && node->right==NULL)
            {
                sum += now;
                return ;
            }
            if (node->left != NULL)
            {
                calcsum(node->left, now*10 + node->left->val, sum);
            }
            if (node->right != NULL)
            {
                calcsum(node->right, now*10 + node->right->val, sum);
            }
        }
        int sumNumbers(TreeNode *root) {
            // Start typing your C/C++ solution below
            //         // DO NOT write int main() function
            //      
            if (root == NULL) return 0;
            int sum = 0;
            calcsum(root, root->val, sum);
            return sum;
        }
};
