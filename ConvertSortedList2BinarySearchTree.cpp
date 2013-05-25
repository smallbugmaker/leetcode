/*************************************************************************
Author: HongYihong
Created Time: Thu 23 May 2013 12:57:24 PM CST
File Name: Work/code/leetcode/ConvertSortedList2BinarySearchTree.cpp
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

struct ListNode {

    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        int getLen(ListNode *head)
        {
            int len = 0;
            ListNode *p = head;
            while (p)
            {
                len++;
                p = p->next;
            }
            return len;
        }

        TreeNode *getTree(ListNode *head, int start, int end)
        {
            if (head==NULL) return NULL;
            if (start >= end) return NULL;
            
            int mid = (start+end)/2;
        //    cout << start << " " << mid << " " << end <<endl;
            ListNode *p = head;
            for (int i = start; i<mid; i++)
              p = p->next;
            TreeNode *left = getTree(head, start, mid);
            TreeNode *right = getTree(p->next, mid+1, end);
            TreeNode *root = new TreeNode(p->val);
            root->left = left;
            root->right = right;
            return root;
        }
        TreeNode *sortedListToBST(ListNode *head) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int len = getLen(head);
            if (len==0) return NULL;
          //  cout << len << endl;
            return getTree(head, 0, len);
        }
};

int main()
{
    ListNode *a = new ListNode(0);
    Solution s;

    s.sortedListToBST(a);
    return 0;
}
