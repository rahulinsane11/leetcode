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
    bool isPalindrome(ListNode* head) { // S.C. = O(1)
        ListNode* mid = middleNode(head); // find middle of the LL
        /* 1->2->3->2->1 has mid=3 and 1->2->3->3->2->1 has mid=3(second 3)*/
        mid = reverseList(mid); // reverse the LL from mid till the end
        /* 1->2->3->3->2->1 becomes 1->2->3->1->2->3 and 1->2->3->2->1 becomes 1->2->1->2->3 */
        ListNode *start1=head, *start2=mid; // start1 moves from head to mid and start2 moves from mid to end
        while(start1 != mid && start2 != NULL)
        {
            if(start1->val != start2->val)
                return false;
            start1=start1->next;
            start2=start2->next;
        }
        return true;
    }
    
    ListNode* middleNode(ListNode* head)
    {
        ListNode *slow=head, *fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode* head)
    {
        ListNode *prev=NULL, *curr=head, *nextnode=head;
        while(nextnode!=NULL)
        {
            nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        head=prev;
        return head;    
    }
};