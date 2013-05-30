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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *res = new ListNode(-1);
        ListNode *now = res;
        
        while (l1 && l2)
        {
            if (l1->val<l2->val)
            {
                now->next = l1;                
                now = now->next;
                l1 = l1->next;
            }
            else
            {
                now->next = l2;
                now = now->next;
                l2 = l2->next;
            }
        }
        if (l1)
        {
            now->next = l1;
        }
        if (l2)
        {
            now->next = l2;
        }
        return res->next;
        
    }
};
