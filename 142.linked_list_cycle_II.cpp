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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head, *fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                return start_of_loop(head,fast);
        }
        return NULL;
    }
    
    ListNode* start_of_loop(ListNode* head, ListNode* end)
    {
        ListNode* start=head;
        while(start!=end)
        {
            start=start->next;
            end=end->next;
        }
        return end; // start == end at this point
    }
};