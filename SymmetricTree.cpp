/*************************************************************************
Author: HongYihong
Created Time: Thu 23 May 2013 10:03:13 PM CST
File Name: Work/code/leetcode/SymmetricTree.cpp
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
#include <stack>
using namespace std;

/**

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//recursively
//class Solution {
//    public:
//        void inorder(TreeNode *root, vector<int> &s)
//        {
//            if (root==NULL) return;
//            if (root->left!=NULL)
//              inorder(root->left, s);
//            s.push_back(root->val);
//            if (root->right!=NULL)
//              inorder(root->right, s);
//        }
//
//        bool isSymmetric(TreeNode *root) {
//            // Start typing your C/C++ solution below
//            // DO NOT write int main() function
//            vector<int> s;
//            vector<int>().swap(s);
//            inorder(root, s);
//            for (int i=0; i<s.size()/2; i++)
//            {
//                if (s[i]!=s[s.size()-i-1])
//                  return false;
//            }
//            return true;
//        }
//};
//

//iteratoration
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root==NULL) return true;
        vector<int> s;
        vector<int>().swap(s);
        
        stack<TreeNode*> st;
        while (st.size()>0) st.pop();
        
        TreeNode* p = root->left;
        st.push(root);
        while(!st.empty() || p)
        {
            while (p)
            {
                st.push(p);
  //              cout << "push " << p->val << endl;
                p = p->left;
            }
            p = st.top();
            st.pop();
//            cout << "pop " <<  p->val << endl;
            s.push_back(p->val); 
            p = p->right;
        } 
        for (int i=0; i<s.size()/2; i++)
            {
                if (s[i]!=s[s.size()-i-1])
                  return false;
            }
        return true;     
    }
};

int main()
{
    TreeNode * a = new TreeNode(1);
    TreeNode * b = new TreeNode(2);
    TreeNode * c = new TreeNode(3);
    TreeNode * d = new TreeNode(4);
    TreeNode * e = new TreeNode(5);
    b->left = c;
    b->right = d;
    a->left = b;
    a->right = e;
    Solution s;

    cout << s.isSymmetric(a) << endl;
    return 0;
}
