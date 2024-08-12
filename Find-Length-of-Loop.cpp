// https://www.geeksforgeeks.org/problems/find-length-of-loop/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-length-of-loop

/*
Given the head of a linked list, determine whether the list contains a loop. If a loop is present, return the number of nodes in the loop, otherwise return 0.
*/



class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(struct Node *head) {
        if(head == NULL || head->next == NULL)
            return 0;
            
        Node* slow = head;
        Node* fast = head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
            {
                int count = 1;
                slow = slow->next;
                while(slow != fast)
                {
                    count++;
                    slow = slow->next;
                }
                return count;
            }
        }
        return 0;
    }
};
