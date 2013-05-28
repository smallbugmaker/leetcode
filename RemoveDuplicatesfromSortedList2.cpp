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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head==NULL || head->next==NULL) return head;
        
        ListNode *h = new ListNode(-100000);
        h->next = head;
        ListNode *pre = h;
        ListNode *p = h;        
        
        while (p && p->next)
        {
            if (p->val == p->next->val)
            {
                ListNode *q = p->next;
                while (q->next && p->val == q->next->val)
                    q = q->next;
                pre->next = q->next;
                p = q->next;                
            }
            else
            {
                pre = p;
                p = p->next;                
            }
        }
        return h->next;
    }
};
