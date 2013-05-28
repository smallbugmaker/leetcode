/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head==NULL || head->next==NULL) return head;
        ListNode * h = new ListNode(-2147483647);
        h->next = head;
        ListNode *pre = h;
        ListNode *p = h;
        
        while (p->next && p->next->val<x)
        {
            pre = p->next;
            p = p->next;
        }
        while (p->next)
        {
            if (p->next->val < x)
            {
                ListNode *preNext = pre->next;
                pre->next = p->next;
                pre = pre->next;
                p->next = p->next->next;                
                pre->next = preNext;            
            }
            else
               p = p->next;            
        }
        return h->next;
    }
};
