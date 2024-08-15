public class IntroductionToLinkedList {
    
}

class Node { 
    int data; 
    Node next; 

    Node() { data = 0; }
    Node(int d) { data = d; }  //constructor to create a new node
} 

/*
 * Geek loves linked list data structure. Given an array of integer arr of size n, Geek wants to construct the linked list from arr.

Construct the linked list from arr and return the head of the linked list.

Example 1:

Input:
n = 5
arr = [1,2,3,4,5]
Output:
1 2 3 4 5
Explanation: Linked list for the given array will be 1->2->3->4->5.
Example 2:

Input:
n = 2
arr = [2,4]
Output:
2 4
Explanation: Linked list for the given array will be 2->4.

https://www.geeksforgeeks.org/problems/introduction-to-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-linked-list
 */


 class Solution {
    static Node constructLL(int arr[]) {
        
        Node head = new Node(arr[0]);
        Node mover = head;
        int n = arr.length;

        for(int i = 1; i<n; i++){
            Node temp = new Node(arr[i]);
            mover.next = temp;
            mover = temp;
        }   

        return head;

    }
}