// https://leetcode.com/problems/partition-list/

/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode();
        ListNode* right = new ListNode();
        ListNode* leftTail = left;
        ListNode* rightTail = right;

        while(head)
        {
            if(head->val < x)
            {
                leftTail->next = head;
                leftTail = leftTail->next;
            }
            else
            {
                rightTail->next = head;
                rightTail = rightTail->next;
            }

            head = head->next;
        }

        leftTail->next = right->next;
        rightTail->next = NULL;
        return left->next;
    }
};
