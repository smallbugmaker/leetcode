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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *h = new ListNode(-1);
        h->next = head;
        ListNode *en = h, *st = h;
        while (n--) en = en->next;
        while (en->next)
        {
            en = en->next;
            st = st->next;
        }
        ListNode *del = st->next;
        st->next = del->next;
        delete del; 
        return h->next;
    }
};
