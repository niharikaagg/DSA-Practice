// https://leetcode.com/problems/sort-list/

/*
Given the head of a linked list, return the list after sorting it in ascending order.
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
    ListNode* findMiddle(ListNode* head)
    {
        ListNode* slow = head;
        // if fast = head, then in case of even nodes, it returns the second middle but we need the first middle
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* mergeLists(ListNode* head1, ListNode* head2)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(head1 != NULL && head2 != NULL)
        {
            if(head1->val < head2->val)
            {
                temp->next = head1;
                head1 = head1->next;
                temp = temp->next;
            }

            else
            {
                temp->next = head2;
                head2 = head2->next;
                temp = temp->next;
            }
        }

        head1 != NULL ? temp->next = head1 : temp->next = head2;
        
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* middle = findMiddle(head);
        
        // separate the left and right halves
        ListNode* leftHalf = head;
        ListNode* rightHalf = middle->next;
        middle->next = NULL;    // detach left half from right half

        // do it till there are single nodes left
        leftHalf = sortList(leftHalf);
        rightHalf = sortList(rightHalf);

        // sort and merge
        return mergeLists(leftHalf, rightHalf);
    }
};
