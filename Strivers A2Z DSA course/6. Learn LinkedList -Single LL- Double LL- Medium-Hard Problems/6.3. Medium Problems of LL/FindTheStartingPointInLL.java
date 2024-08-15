public class FindTheStartingPointInLL{

}

/*
 * Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

https://leetcode.com/problems/linked-list-cycle-ii/description/
 */


  class ListNode {
      int val;
     ListNode next;
      ListNode(int x) {
          val = x;
          next = null;
     }
  }


  /*
   * length of list till the cycle node = L1
   * 
   * when the slow pointer is at cycle node the it has travelled L1 distance and as fast
   * pointer is going twice the speed it has travelled L1 more i.e. 2*L1 in total, L1 Out
   * of the loop and L1 inside the loop
   * 
   * Now let the distance between fast and slow at this point be d, so the loop length will 
   * be L1 + d;
   * 
   * Now we will continue the loop, as the distance is d between two pointers and slow
   * is going with speed of 1 it will take slow a distance of d to meet the fast pointer
   * 
   * so now from the cycle node slow has travelled a distance of d and now the distance
   * to cycle node and slow has become L1 which is same distance as head to cycle node.
   * 
   * now we will place fast at head and move fast and slow both at speed of 1 and the point 
   * they meet will be the cycle node.
   * 
   */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        
        ListNode slow = head;
        ListNode fast = head;

        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast){
                fast = head;
                while(slow != fast){
                    fast = fast.next;
                    slow = slow.next;
                }
                return slow;
            }
        }


        return null;


    }
}