// https://www.geeksforgeeks.org/problems/introduction-to-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-linked-list

/*
Given an array of integer arr. Your task is to construct the linked list from arr & return the head of the linked list.
*/



class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        
        if(arr.empty())
            return NULL;
            
        Node* head = new Node(arr[0]);
        Node* current = head;
        
        for(int i=1; i<arr.size(); i++)
        {
            Node* newNode = new Node(arr[i]);
            current->next = newNode;
            current = newNode;
        }
        
        return head;
    }
};
