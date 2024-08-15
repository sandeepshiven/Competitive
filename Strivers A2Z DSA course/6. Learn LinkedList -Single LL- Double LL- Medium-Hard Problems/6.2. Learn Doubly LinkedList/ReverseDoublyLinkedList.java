public class ReverseDoublyLinkedList{

}

/*Given a doubly linked list of n elements. Your task is to reverse the doubly linked list in-place.

Example 1:

Input:
LinkedList: 3 <--> 4 <--> 5
Output: 5 4 3
Example 2:

Input:
LinkedList: 75 <--> 122 <--> 59 <--> 196
Output: 196 59 122 75
Your Task:
Your task is to complete the given function reverseDLL(), which takes head reference as argument and this function should reverse the elements such that the tail becomes the new head and all pointers are pointing in the right order. You need to return the new head of the reversed list. The printing and verification is done by the driver code.

https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-a-doubly-linked-list

*/

class Node
{
    int data;
    Node next, prev;
    Node(int data)
    {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

public static Node reverseDLL(Node  head)
{
    //Your code here

    Node mover = head;
    while(mover.next != null){
        Node temp = mover.next;
        mover.next = mover.prev;
        mover.prev = temp;
        mover = temp;
    }
    Node temp = mover.next;
    mover.next = mover.prev;
    mover.prev = temp;
    return mover;

}