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
    ListNode *merge2Lists(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode(-1);
        ListNode *p = res;
        while (l1 && l2)
        {
            if (l1->val<l2->val)
            {
                p->next = l1;                
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1)
        {
            p->next = l1;
        }
        if (l2)
        {
            p->next = l2;
        }
        return res->next;
    }
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *res = NULL;
        for (int i=0; i<lists.size(); i++)
        {
            res = merge2Lists(res, lists[i]);
        }
        return res;
    }
};
