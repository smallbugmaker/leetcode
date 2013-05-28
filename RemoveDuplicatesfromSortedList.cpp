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
        ListNode *p = head;
        ListNode *q = head;
        
        while (p && p->next)
        {
            if (p->val==p->next->val)
            {
                p->next = p->next->next;
            }
            else p = p->next;
        }
        return head;
    }
};
