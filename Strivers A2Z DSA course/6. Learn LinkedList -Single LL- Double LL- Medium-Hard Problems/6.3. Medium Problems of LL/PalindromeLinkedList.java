public class PalindromeLinkedList {
    
}
/*
 * Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].

https://leetcode.com/problems/palindrome-linked-list/description/

 */
public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    // we can store values in a list and then check if palindrome or not it will take extra space
    /*
     * for sloving using constant space we will reverse the list from half and then check
     */
    public ListNode reverse(ListNode head){
        
        ListNode prev = null;
        while(head != null){
            ListNode temp = head.next;
            head.next = prev;
            prev = head;
            head = temp;
        }

        return prev;

    }

    public boolean isPalindrome(ListNode head) {
        
        ListNode fast = head;
        ListNode slow = head;

        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }

        slow = reverse(slow);
        fast = head;
        while (slow != null ) {
            if(fast.val != slow.val){
                return false;
            }
            slow = slow.next;
            fast = fast.next;
        }

        return true;
    }
}
