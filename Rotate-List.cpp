// https://leetcode.com/problems/rotate-list/

/*
Given the head of a linked list, rotate the list to the right by k places.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;

        ListNode* tail = head;
        int nodes = 1;

        while(tail->next != NULL)
        {
            nodes++;
            tail = tail->next;
        }

        tail->next = head;

        k = k % nodes;
        ListNode* temp = head;
        for(int i=1; i<nodes-k; i++)
            temp = temp->next;

        head = temp->next;
        temp->next = NULL;

        return head;
    }
};
