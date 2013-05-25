/*************************************************************************
Author: HongYihong
Created Time: Wed 22 May 2013 08:37:58 PM CST
File Name: Work/code/leetcode/PopulatingNextRightPointerinEachNode2.cpp
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

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


class Solution {
    public:
        void connect(TreeLinkNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if (root == NULL) return;

            TreeLinkNode *start, *p, *q;

            root->next = NULL;
            start = root;

            while(start!=NULL)
            {
                bool flag = false;
                q = start;
                p = NULL;
                start = NULL;
                while (q!=NULL)
                {
//                    cout << "1: " << q->val << endl;
                    if (q->left!=NULL)
                    {
//                        cout << "2: " << q->left->val << endl;
                        if (flag==false)
                        {
                            start = q->left;
                            p = q->left;
                            flag = true;
                        }
                        else
                        {
                            p->next = q->left;
                            p = p->next;
                        }
                    }
                    if (q->right!=NULL)
                    {
//                        cout << "3: " << q->right->val << endl;
                        if (flag==false)
                        {
                            start = q->right;
                            p = q->right;
                            flag = true;
                        }
                        else
                        {
                            p->next = q->right;
                            p = p->next;
                        }
                    }
//                    cout << "4: " << q->val << endl;
                    if (q->next==NULL) break;
                    q = q->next;
//                    cout << "5: " << q->val << endl;
                }
            }

        }
};

int main()
{
    TreeLinkNode *a = new TreeLinkNode(1);
    TreeLinkNode *b = new TreeLinkNode(2);
    TreeLinkNode *c = new TreeLinkNode(3);
    a->left = b;
    a->right = c;
    Solution s;
    s.connect(a);
//    TreeLinkNode *a(1);
//    TreeLinkNode *a(1);
    return 0;
}
