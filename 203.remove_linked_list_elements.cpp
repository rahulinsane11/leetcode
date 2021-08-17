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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) // LL is of 0 length
            return head;
        ListNode *dummy = new ListNode(-1); // dummy node
        dummy->next=head; // make dummy node the first node of LL
        ListNode *curr=head, *prev=dummy;
        while(curr!=NULL)
        {
            if(curr->val==val)
            {
                prev->next=curr->next;
                delete curr;
                curr=prev->next;
            }
            else
            {
                curr=curr->next;
                prev=prev->next;
            }
        }
        head=dummy->next;
        delete dummy;
        return head;
    }
};