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
    void deleteNode(ListNode* node) {
        ListNode *del_node;
        node->val=node->next->val; // copy the value of next node to the current node
        del_node=node->next;
        node->next=node->next->next; // skip the next node of current node
        delete del_node;
    }
};