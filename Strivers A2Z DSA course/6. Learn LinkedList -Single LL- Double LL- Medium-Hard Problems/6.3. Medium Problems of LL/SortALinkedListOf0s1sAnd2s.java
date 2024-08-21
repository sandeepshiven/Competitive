import java.util.*;
import java.lang.*;

public class SortALinkedListOf0s1sAnd2s {
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
       
        head = Solution.segregate(head.next);
        System.out.println("Solution");
        while (head != null){
            System.out.print(head.data + ", ");
            head = head.next;    
        }
    }
}
/*
 * Given a linked list where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to the head side, 2s at the end of the linked list, and 1s in the middle of 0s and 2s.

Examples:

Input: LinkedList: 1->2->2->1->2->0->2->2
Output: 0->1->1->2->2->2->2->2
Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.
 
Input: LinkedList: 2->2->0->1
Output: 0->1->2->2
Explanation: After arranging all the 0s,1s and 2s in the given format, the output will be 0 1 2 2.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1 <= no. of nodes <= 106
0 <= node->data <= 2

https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=given-a-linked-list-of-0s-1s-and-2s-sort-it
 */

 class Node
{
    int data;
    Node next;
    Node(int data)
    {
        this.data = data;
        next = null;
    }
}

class Solution {
    // Function to sort a linked list of 0s, 1s and 2s.
    // using dummy nodes
    static Node segregate(Node head) {
        Node dZero = new Node(-1);
        Node dOne = new Node(-1);
        Node dTwo = new Node(-1);

        Node dZTemp = dZero;
        Node dOTemp = dOne;
        Node dTTemp = dTwo;

        if(head == null || head.next == null){
            return head;
        }

        while(head != null){
            if(head.data == 0){
                dZTemp.next = head;
                dZTemp = dZTemp.next;
            }
            else if(head.data == 1){
                dOTemp.next = head;
                dOTemp = dOTemp.next;
            }
            else{
                dTTemp.next = head;
                dTTemp = dTTemp.next;
            }
            head = head.next;
        }
        dZTemp.next = (dOne.next != null)?dOne.next : dTwo.next;
        dOTemp.next = dTwo.next;
        dTTemp.next = null;
        return dZero.next; 
    }
}