// https://leetcode.com/problems/reverse-linked-list-ii/

/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* leftPrev = dummy;
        ListNode* curr = head;

        // reach curr pointer to left
        for(int i=1; i<left; i++)
        {
            leftPrev = leftPrev->next;
            curr = curr->next;
        }

        // reverse between left and right
        ListNode* prev = NULL;
        for(int i=0; i<right-left+1; i++)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // make new links
        leftPrev->next->next = curr;
        leftPrev->next = prev;

        return dummy->next;
    }
};
