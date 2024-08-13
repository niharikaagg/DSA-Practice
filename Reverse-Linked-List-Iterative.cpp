// https://leetcode.com/problems/reverse-linked-list/description/

/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
*/



class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;

        if(head->next == NULL)
            return head;

        ListNode* back = NULL;
        ListNode* current = head;
        ListNode* front = head->next;

        while(front != NULL)
        {
            current->next = back;
            back = current;
            current = front;
            front = front->next;
        }
        current->next = back;
        head = current;

        return head;
    }
};
