import java.util.*;
import java.lang.*;

public class Add1ToALinkedListNumber {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size: ");  
        
        int n=sc.nextInt();  
        System.out.println("Enter the elements : "); 
        Node head = new Node(-1); 
        Node temp = head;
        for(int i=0; i<n; i++) {  
            
            int x = sc.nextInt();
            temp.next = new Node(x);
            temp = temp.next;
        }  
        Solution sol = new Solution();
        
        head = sol.addOne(head.next);
        System.out.println("Solution");
        sol.printList(head);
    }
}

/*
 * You are given a linked list where each element in the list is a node and have
 * an integer data. You need to add 1 to the number formed by concatinating all
 * the list node numbers together and return the head of the modified linked
 * list.
 * 
 * Note: The head represents the first element of the given array.
 * 
 * Examples :
 * 
 * Input: LinkedList: 4->5->6
 * Output: 457
 * 
 * Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457.
 * Input: LinkedList: 1->2->3
 * Output: 124
 * 
 * Explanation: 1->2->3 represents 123 and when 1 is added it becomes 124.
 * 
 * https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-
 * linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&
 * utm_campaign=add-1-to-a-number-represented-as-linked-list
 */

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

class Solution {

    public void printList(Node head){
        System.out.print("List: ");
        while (head != null) {
            System.out.print(head.data + ", ");
            head = head.next;
        }
        
    }

    public Node reverseNode(Node head) {

        Node mover = head;
        Node prev = null;
        while (mover != null) {
            Node temp = mover.next;
            mover.next = prev;
            prev = mover;
            mover = temp;
        }
        
        return prev;
    }

    // `need to iterate 3 times
    public Node addOne(Node head) {

        head = reverseNode(head);
        Node mover = head;
        Node prev = null;

        int carry = 1;
        while (mover != null) {
            int val = carry + mover.data;
            if ((val / 10) > 0) {
                int rem = val%10;
                val = val/10;
                mover.data = rem;
                carry = val;
            }
            else{
                carry = 0;
                mover.data = val;
            }
            prev = mover;
            mover = mover.next;
        }
        if(carry != 0){
            Node node = new Node(carry);
            prev.next = node;
            
        }
        return reverseNode(head);
    }

    // using bactracking

    public int helper(Node head){
        if(head == null){
            return 1;
        }
        int carry = helper(head.next);
        int val = head.data + carry;
        if((val/10) > 0){
            head.data = val%10;
            return val/10;
        }
        head.data = val;
        return 0;
    }

    public Node addOne1(Node head) {

        int carry = helper(head); 
        if(carry > 0){
            Node node = new Node(carry);
            node.next = head;
            return node;
        }
        return head;
    }
}
