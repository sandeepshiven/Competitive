public class DeleteNodeInDoublyLinkedList {
    
}

/*
 * 
 * Given a doubly Linked list and a position. The task is to delete a node from a given position (position starts from 1) in a doubly linked list and return the head of the doubly Linked list.

Examples:

Input: LinkedList = 1 <--> 3 <--> 4, x = 3
Output: 1 3  
Explanation: After deleting the node at
position 3 (position starts from 1),
the linked list will be now as 1->3.
Input: LinkedList = 1 <--> 5 <--> 2 <--> 9, x = 1
Output: 5 2 9

https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-node-in-doubly-linked-list
 * 
 */

 class Node
{
	int data;
	Node next;
	Node prev;
	Node(int d)
	{
		data = d;
		next = prev = null;
	}
}

class Solution
{
    // function returns the head of the linkedlist
    Node deleteNode(Node head,int x)
    {
        if(x == 1){
            head.next.prev = null;
            head = head.next;
            return head;
        }

        Node mover = head;

        while(x != 1){
            mover = mover.next;
            x--;
        }
        mover.prev.next = mover.next;
        // for last node
        if(mover.next != null)
            mover.next.prev = mover.prev;

        return head;

    }
}










