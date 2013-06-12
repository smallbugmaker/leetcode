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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head==NULL || k==1) return head;
        ListNode *h = new ListNode(-1);;
        h->next = head;
        ListNode *pos = head, *st = h;
        int r = 1;
        
        while (pos && pos->next)
        {
            ListNode *pnn = pos->next->next;
            pos->next->next = st->next;
            st->next = pos->next;
            pos->next = pnn;            
            r++;
            if (k==r)
            {
                r = 1;
                st = pos;
                pos = st->next;
            }        
        }
        if (r!=1)
        {
            pos = st->next;
            while (pos && pos->next)
            {
                ListNode *pnn = pos->next->next;
                pos->next->next = st->next;
                st->next = pos->next;
                pos->next = pnn;  
            }
        }
       
        return h->next;
    }
};
