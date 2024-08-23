public class RemoveDuplicatesFromSortedDLL {
    
}

/*
 * Given a doubly linked list of n nodes sorted by values, the task is to remove duplicate nodes present in the linked list.

Example 1:

Input:
n = 6
1<->1<->1<->2<->3<->4
Output:
1<->2<->3<->4
Explanation:
Only the first occurance of node with value 1 is 
retained, rest nodes with value = 1 are deleted.
Example 2:

Input:
n = 7
1<->2<->2<->3<->3<->4<->4
Output:
1<->2<->3<->4
Explanation:
Only the first occurance of nodes with values 2,3 and 4 are 
retained, rest repeating nodes are deleted.
Your Task:
You have to complete the method removeDuplicates() which takes 1 argument: the head of the linked list.  Your function should return a pointer to a linked list with no duplicate element.

https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=remove-duplicates-from-a-sorted-doubly-linked-list
 */

 class Node{
    int data;
    Node next, prev;
    Node(int x){
        this.data = x;
        this.next = null;
        this.prev = null;
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    Node removeDuplicates(Node head){
        
        if(head == null || head.next == null){
            return head;
        }
        
        Node prev = head;
        while (head.next != null && prev.data == head.next.data) {
            head = head.next;
        }
        
        if(prev != head){
            prev = head; 
            prev.prev = null;
        }
        head = prev;
        Node mover = head;
        while (mover.next != null) {
            Node temp = mover.next;
            if(temp.data == mover.data){
                while (temp != null && temp.data == mover.data) {
                    temp = temp.next;
                }
                mover.next = temp;
                if(temp != null)   temp.prev = mover;
                
            }            
            mover = mover.next;
            
        }
        return head;

        
    }

    Node removeDuplicates1(Node head){
        
        if(head == null || head.next == null){
            return head;
        }
        
        Node temp = head;
        
        while (temp!= null && temp.next != null) {
            
            Node nextNode = temp.next;
            while(nextNode != null && nextNode.data == temp.data){
                nextNode = nextNode.next;
            }
            temp.next = nextNode;
            if(nextNode != null) nextNode.prev = temp;
            temp = temp.next;
            
        }
        return head;

        
    }
}