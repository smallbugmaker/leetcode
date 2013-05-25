/*************************************************************************
Author: HongYihong
Created Time: Fri 01 Mar 2013 05:14:49 PM CST
File Name: Code/code/leetcode/addTwoNumbers.cpp
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

class Solution {
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            ListNode *res = NULL;
            ListNode *head = NULL;
            int carry = 0;
            while (l1 != NULL && l2 != NULL)
            {
                int num = l1->val + l2->val + carry;
  //              cout << num << endl;
                carry = num/10;
                ListNode *r = new ListNode(num%10);
//                cout << carry << endl;
                if (res==NULL)
                {
                    res = r;
                    head = res;
                }
                else
                {
                  res->next = r;
                  res = res->next;
                }
                //cout << res->val << endl;
                l1 = l1->next;
                l2 = l2->next;
            }
            while (l1 != NULL)
            {
                int num = l1->val + carry;
                carry = num/10;
                ListNode *r = new ListNode(num%10);
                if (res==NULL)
                {
                    res = r;
                    head = res;
                }
                else
                {
                  res->next = r;
                  res = res->next;
                }
                l1 = l1->next;
            }
            while (l2 != NULL)
            {
                int num = l2->val + carry;
                carry = num/10;
                ListNode *r = new ListNode(num%10);
                if (res==NULL)
                {
                    res = r;
                    head = res;
                }
                else
                {
                  res->next = r;
                  res = res->next;
                }
                l2 = l2->next;
            }  
            if (carry!=0)
            {
                ListNode *r = new ListNode(carry);
                res->next = r;
            }
        /*    ListNode *p = head;
            while (p!=NULL)
            {
                cout << p->val << " ";
                p = p->next;
            }
            cout << endl;*/
            return head;
        }
};

int main()
{
    ListNode *l1 = new ListNode(2);
    ListNode *l12 = new ListNode(4);
    ListNode *l13 = new ListNode(3);
    l1->next = l12;
    l1->next->next = l13;

    ListNode *l2 = new ListNode(5);
    ListNode *l22 = new ListNode(6);
    ListNode *l23 = new ListNode(4);
    l2->next = l22;
    l2->next->next = l23;

    Solution s;
    ListNode *p;
    p = s.addTwoNumbers(l1, l2);
    return 0;
}
