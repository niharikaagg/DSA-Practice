// https://leetcode.com/problems/reverse-nodes-in-k-group/

/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
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
    ListNode* findKthNode(ListNode* head, int k)
    {
        ListNode* kNode = head;
        k--;
        while(kNode != NULL && k > 0)
        {
            kNode = kNode->next;
            k--;
        }

        return kNode;
    }

    ListNode* reverse(ListNode* head)
    {
        ListNode* back = NULL;
        ListNode* current = head;
        ListNode* front = head->next;

        while(current != NULL)
        {
            front = current->next;
            current->next = back;
            back = current;
            current = front;
        }

        return back;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nextNode = NULL; // to store start of next unsorted group
        ListNode* prevNode = NULL; // to store end of just sorted group

        // do for all groups
        while(temp != NULL)
        {
            ListNode* kNode = findKthNode(temp, k);

            // if not a k-size group
            if(kNode == NULL)
            {
                if(prevNode)    // if the first group is not k-sized, there will be no prevNode
                    prevNode->next = temp;    // directly point prevNode to temp, which is the head of next group

                break;
            }

            nextNode = kNode->next; // store next node
            kNode->next = NULL; // isolate the k-group
            
            kNode = reverse(temp); // reverse the k-group;

            if(temp == head) // if first group
                head = kNode; // new head will be kNode, kNode is the head of reversed list
            else
                prevNode->next = kNode; // kNode is the head of reversed list

            prevNode = temp; // prevNode is now the head of original list, since it is at end when reversed
            temp = nextNode; // temp goes to head of next unsorted segment
        }

        return head;
    }
};
