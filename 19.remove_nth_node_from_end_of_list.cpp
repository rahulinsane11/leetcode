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
    ListNode* removeNthFromEnd(ListNode* head, int n) { // 2 pass soln.
        ListNode *dummy = new ListNode(-1);
        dummy->next=head;
        int c=0;
        ListNode *curr=head, *temp;
        while(curr!=NULL)
        {
            c++;
            curr=curr->next;
        }
        curr=dummy;
        for(int i=1; i<=c-n; i++)
            curr=curr->next;
        temp=curr->next;
        curr->next=curr->next->next;
        delete temp;
        head=dummy->next;
        delete dummy;
        return head;
    }
};