// https://leetcode.com/problems/intersection-of-two-linked-lists/

/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:


The test cases are generated such that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.
*/



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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        
        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while(t1 != t2)
        {
            t1 = (t1 == NULL) ? headB : t1->next;
            t2 = (t2 == NULL) ? headA : t2->next;
        }

        return t1;

        // while(t1 != t2)
        // {
        //     if(t1 == NULL)
        //     {
        //         t1 = headB;
        //         t2 = t2->next;
        //     }
            
        //     else if(t2 == NULL)
        //     {
        //         t2 = headA;
        //         t1 = t1->next;
        //     }

        //     else
        //     {
        //         t1 = t1->next;
        //         t2 = t2->next;
        //     }
        // }

        // return t1;
    }
};
