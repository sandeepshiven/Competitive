
public class ReverseLinkedList{

}





/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000

https://leetcode.com/problems/reverse-linked-list/description/
 * 
 */



public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
 
class Solution {
    public ListNode reverseListIterative(ListNode head) {
        
        if(head == null){
            return head;
        }
        ListNode prev = null;
        while(head != null){
            ListNode temp = head.next;
            head.next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }

    public ListNode helper(ListNode node, ListNode prev){
        if(node.next == null){
            return node;
        }
        ListNode temp = node.next;
        node.next = prev;
        prev = node;
        node = temp;
        return helper(node, prev);
    }

    public ListNode reverseListRecursive(ListNode head) {
        
        if(head==null || head.next == null){
            return head;
        }
        
        

        return helper(head, null);

    }

    public ListNode reverseListRecursive2(ListNode head) {
        
        if(head==null || head.next == null){
            return head;
        }
        
        ListNode newHead = reverseListRecursive2(head.next);
        ListNode front = head.next;
        
        front.next = head;
        head.next = null; 

        return newHead;
    }
}







