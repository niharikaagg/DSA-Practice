// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/



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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;  // to move n steps first

        for(int i=0; i<n; i++)
            fast = fast->next;

        if(fast == NULL)
        {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        ListNode* slow = head;

        // now move fast and slow together so that slow reaches one node before the node to be deleted, fast is already ahead by n steps
        while(fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
    }
};
