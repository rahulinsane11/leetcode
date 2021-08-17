/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) { // 1 pass soln.
        ListNode *dummy = new ListNode(-1);
        dummy->next=head;
        ListNode *first=dummy, *second=head, *temp;
        for(int i=1; i<=n; i++) // to generate a gap of n b/w first and second pointers
            second=second->next;
        while(second!=NULL)
        {
            first=first->next;
            second=second->next;
        }
        temp=first->next;
        first->next=first->next->next;
        delete temp;
        head=dummy->next;
        delete dummy;
        return head;
    }
};