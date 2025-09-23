// https://leetcode.com/problems/merge-two-sorted-lists/

/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1;
        ListNode* t2 = list2;
      // t1 andd t2 are actually not required, use list1 and list2 itself
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(t1 != NULL && t2 != NULL)
        {
            if(t1->val <= t2->val)
            {
                temp->next = t1;
                t1 = t1->next;
            }

            else
            {
                temp->next = t2;
                t2 = t2->next;
            }

            temp = temp->next;
        }

        t1 != NULL ? temp->next = t1 : temp->next = t2;

        return dummy->next;
    }
};
