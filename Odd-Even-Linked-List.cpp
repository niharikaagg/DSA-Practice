// https://leetcode.com/problems/odd-even-linked-list/description/

/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.
*/



class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return NULL;

        if(head->next == NULL)
            return head;

        if(head->next->next == NULL)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* oddHead = head;
        ListNode* evenHead = head->next;

        while(even!=NULL && even->next!=NULL)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return oddHead;
    }
};
