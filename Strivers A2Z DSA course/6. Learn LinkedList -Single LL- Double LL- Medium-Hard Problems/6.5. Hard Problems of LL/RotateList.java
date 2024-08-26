public class RotateList {
    
}

/*
 * Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

https://leetcode.com/problems/rotate-list/description/
 */


 class ListNode {
      int val;
      ListNode next;
      ListNode() {}
      ListNode(int val) { this.val = val; }
      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
  }
 
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        
        if(head == null || head.next == null || k==0){
            return head;
        }

        int size = 1;
        ListNode temp = head;

        while(temp.next != null){
            size++;
            temp = temp.next;
        }

        k = k%size;           
        
        if(k == 0){
            return head;
        }

        temp.next = head;
        
        k = size - k;
        k--;
        temp = head;
        while (k>0) {
            temp = temp.next;
            k--;
        }
        head = temp.next;
        temp.next = null;
          

        return head;
    }
}
