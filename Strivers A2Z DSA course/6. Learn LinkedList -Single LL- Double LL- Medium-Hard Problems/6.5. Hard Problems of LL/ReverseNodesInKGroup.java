public class ReverseNodesInKGroup {
    
}

/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 
https://leetcode.com/problems/reverse-nodes-in-k-group/description/
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

    public ListNode reverseNodes(ListNode startNode){
        if(startNode == null || startNode.next == null){
            return startNode;
        }

        ListNode prev = null;
        ListNode startTemp = startNode;
        while(startTemp != null){
            ListNode temp = startTemp.next;
            startTemp.next = prev;
            prev = startTemp;
            startTemp = temp;
        }
        return prev;
    }

    public ListNode findKthNode(ListNode head, int k){
        int count =1;
        while(head != null && count != k){
            head = head.next;
            count++;
        }
        return head;
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        
        ListNode temp = head;
        ListNode nextNode = null;
        ListNode prevNode = null;
        ListNode kthNode = null;
        while (temp != null) {
            kthNode = findKthNode(temp, k);
            if(kthNode == null){
                if(prevNode != null){
                    prevNode.next = temp;
                }
                break;
            }

            nextNode = kthNode.next;
            kthNode.next = null;
            reverseNodes(temp);

            if(temp == head){
                head = kthNode;
            }
            else{
                prevNode.next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }

        return head;
    }
}