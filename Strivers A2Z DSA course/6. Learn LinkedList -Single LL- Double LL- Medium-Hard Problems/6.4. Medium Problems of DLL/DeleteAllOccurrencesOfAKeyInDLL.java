public class DeleteAllOccurrencesOfAKeyInDLL {
    
}

/*
 * You are given the head_ref of a doubly Linked List and a Key. Your task is to delete all occurrences of the given key if it is present and return the new DLL.

Example1:

Input: 
2<->2<->10<->8<->4<->2<->5<->2
2
Output: 
10<->8<->4<->5
Explanation: 
All Occurences of 2 have been deleted.

Example2:

Input: 
9<->1<->3<->4<->5<->1<->8<->4
9
Output: 
1<->3<->4<->5<->1<->8<->4
Explanation: 
All Occurences of 9 have been deleted.
Your Task:

Complete the function void deleteAllOccurOfX(struct Node** head_ref, int key), which takes the reference of the head pointer and an integer value key. Delete all occurrences of the key from the given DLL.

https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list
 * 
 */


 class Node
{
	int data;
	Node next;
	Node prev;
	Node(int data)
	{
	    this.data = data;
	    next = prev = null;
	}
}
class Solution {
    static Node deleteAllOccurOfX(Node head, int x) {
        
        
        Node mover = head;

        while(mover != null && mover.data == x){
            mover = mover.next;
        }
        if(mover == null){
            return null;
        }
        mover.prev = null;
        head = mover;
        Node prev = null;
        while(mover != null){
            if(mover.data == x){
                prev.next = mover.next;
                if(mover.next != null){
                    mover.next.prev = prev;
                }
            }
            else{
                prev = mover;
            }
            
            mover = mover.next;
        }
        prev.next = null;
        return head;
    }
}
