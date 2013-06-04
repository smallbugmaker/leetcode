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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head==NULL) return NULL;
        ListNode *h = new ListNode(-1);
        h->next = head;
        ListNode *p = h;
        int n = 0;
        while (p)
        {
            if (n%2==0 && p->next && p->next->next)
            {
                ListNode *pnn = p->next->next;
                p->next->next = pnn->next;
                pnn->next = p->next;
                p->next = pnn;
            }
            n++;
            p = p->next;
        }
        return h->next;
    }
};
