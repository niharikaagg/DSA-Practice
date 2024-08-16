// https://leetcode.com/problems/palindrome-linked-list/description/

/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
*/



class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL)
            return true;

        if(head->next == NULL)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* back = NULL;
        ListNode* current = head;
        ListNode* front = head->next;

        while(current!=slow)
        {
            current->next = back;
            back = current;
            current = front;
            front = front->next;
        }

        if(fast!=NULL)
            slow = slow->next;      // to skip middle element in odd length

        head = back;

        ListNode* temp = head;

        while(temp!=NULL && slow!=NULL)
        {
            if(temp->val != slow->val)
                return false;
            
            slow = slow->next;
            temp = temp->next;
        }
        return true;
    }
};
