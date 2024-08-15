public class IntroductionToDoublyLinkedList {
    
}


/*
 * 
 * Geek is learning data structures and is familiar with linked lists, but he's curious about how to access the previous element in a linked list in the same way that we access the next element. His teacher explains doubly linked lists to him.

Given an integer array arr of size n. Construct the doubly linked list from arr and return the head of it.

Example 1:

Input:
n = 5
arr = [1,2,3,4,5]
Output:
1 2 3 4 5
Explanation: Linked list for the given array will be 1<->2<->3<->4<->5.
Example 2:

Input:
n = 1
arr = [1]
Output:
1
Explanation: Linked list for the given array will be 1.

https://www.geeksforgeeks.org/problems/introduction-to-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-doubly-linked-list
 * 
 */

 class Node {
    int data;
    Node next;
    Node prev;

    Node(int x) {
        data = x;
        next = null;
        prev= null;
    }

} 

class Solution {
    Node constructDLL(int arr[]) {
        
        Node head = new Node(arr[0]);
        Node mover = head;
        int n = arr.length;
        for(int i=1; i<n; i++){
            Node temp = new Node(arr[i]);
            temp.prev = mover;
            mover.next = temp;
            mover = temp;
        }


        return head;

    }
}