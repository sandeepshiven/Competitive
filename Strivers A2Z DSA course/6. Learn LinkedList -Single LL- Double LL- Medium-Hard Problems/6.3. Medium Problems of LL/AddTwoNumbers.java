public class AddTwoNumbers {

}
/*
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 * Example 2:
 * 
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 * Example 3:
 * 
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 * 
 * 
 * https://leetcode.com/problems/add-two-numbers/description/
 */

class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        ListNode temp1 = l1;
        ListNode temp2 = l2;
        ListNode res = new ListNode();
        ListNode tempRes = res;
        int carry = 0;
        while (temp1 != null || temp2 != null || carry > 0) {

            int val = carry;

            if (temp1 != null) {
                val += temp1.val;
                temp1 = temp1.next;
            }
            if (temp2 != null) {
                val += temp2.val;
                temp2 = temp2.next;
            }

            carry = val / 10;
            val = val % 10;

            tempRes.next = new ListNode(val);
            tempRes = tempRes.next;
            
        }

        return res.next;
    }
}
