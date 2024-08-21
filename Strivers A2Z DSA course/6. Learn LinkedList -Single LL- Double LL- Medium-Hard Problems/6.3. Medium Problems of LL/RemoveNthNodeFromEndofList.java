public class RemoveNthNodeFromEndofList{

}

/*
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 * 
 * 
 * 
 */ 
 class ListNode {
         int val;
      ListNode next;
      ListNode() {}
      ListNode(int val) { this.val = val; }
      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
  }
 
class Solution {
    // 2 pass using counter to get length of the list
    public ListNode removeNthFromEnd(ListNode head, int n) {
        
        int count = 0;
        ListNode mover = head;
        while(mover != null){
            count++;
            mover = mover.next;
        }
        if(n == count){
            return head.next;
        }
        else{
            mover = head;
            while(count-1 != n){
                mover = mover.next;
                count--;
            }
            mover.next = mover.next.next;
        }


        return head;
    }

    // 1 pass - making fast go n ahead, then moving them together, so when fast is at end
    // there will distance of n between them and slow is nth from back
    public ListNode removeNthFromEnd2(ListNode head, int n) {
        
        
        ListNode fast = head, slow = head;
        while(n != 0){
            n--;
            fast = fast.next;
        }
        if(fast == null){
            return head.next;
        }
        else{
            while(fast.next != null){
                slow = slow.next;
                fast = fast.next;
            }
            slow.next = slow.next.next;
        }


        return head;
    }
}