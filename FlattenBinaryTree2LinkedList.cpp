/*************************************************************************
Author: HongYihong
Created Time: Wed 22 May 2013 09:33:12 PM CST
File Name: Work/code/leetcode/FlattenBinaryTree2LinkedList.cpp
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

struct Node
{
    TreeNode *head;
    TreeNode *tail;
    Node(){}
    Node(TreeNode *h, TreeNode *t):head(h), tail(t){}
};

class Solution {
    public:
        Node convert(TreeNode *root)
        {
            if (root == NULL)
              return Node(NULL, NULL);

            Node leftNode = convert(root->left);
            Node rightNode = convert(root->right);

            root->right = NULL;
            root->left = NULL;

            if (leftNode.head)
            {
                root->right = leftNode.head;
                leftNode.tail->right = rightNode.head;

            }
            else
            {
                root->right = rightNode.head;
            }

            TreeNode *tail;
            if (rightNode.tail != NULL)
              tail = rightNode.tail;
            else if (leftNode.tail != NULL)
              tail = leftNode.tail;
            else
              tail = root;

            return Node(root, tail);
        }

        void flatten(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            convert(root);
        }
};

