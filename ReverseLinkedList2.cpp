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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head==NULL || m==n) return head;
        ListNode *h = new ListNode(-1);
        h->next = head;
        ListNode *p = h;
        ListNode *start = h;
        for (int i=0; i<m; i++)
        {
            start = p;
            p = p->next;            
        }
                
        if (m+1==n)
        {
            int temp = p->val;
            p->val = p->next->val;
            p->next->val = temp;
            return head;
        }
        for (int i=m; i<n; i++)
        {
            ListNode *next = start->next;
            ListNode *pre = p; 
            p = p->next;
            pre->next = p->next;
            start->next = p;
            p->next = next;
            p = pre;
        }
        return h->next;
    }
};
