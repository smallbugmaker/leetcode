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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int n = 0;
        ListNode *p = head;
        ListNode *res = NULL;
        
        while (p)
        {
            n++;
            p = p->next;
        }
        
        if (n<2) return head;
        k = k%n;
        if (n==k || k==0) return head;
        
        int m = n-k;
        p = head;
        
        while (m>1)
        {
            p = p->next;
            m--;
        }
        res = p->next;
        p->next = 0;
        p = res;
        while (p->next)
        {
            p = p->next;
        }
        p->next = head;
        return res;        
    }
};
