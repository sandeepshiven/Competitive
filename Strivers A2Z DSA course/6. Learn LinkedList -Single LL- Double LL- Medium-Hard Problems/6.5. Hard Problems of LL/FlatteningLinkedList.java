public class FlatteningLinkedList {
    
}
/*
 * Given a Linked List, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked lists is in sorted order.
Flatten the Link List so all the nodes appear in a single level while maintaining the sorted order.

Note: The flattened list will be printed using the bottom pointer instead of the next pointer. Look at the printList() function in the driver code for more clarity.

Examples:

Input:

Output:  5-> 7-> 8- > 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation: The resultant linked lists has every node in a single level.(Note: | represents the bottom pointer.)
Input:
 
Output: 5-> 7-> 8-> 10-> 19-> 22-> 28-> 30-> 50
Explanation: The resultant linked lists has every node in a single level.(Note: | represents the bottom pointer.)
Note: In the output section of the above examples, the -> represents the bottom pointer.

https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flattening-a-linked-list
 */

 class Node {
    int data;
    Node next;
    Node bottom;

    Node(int x) {
        data = x;
        next = null;
        bottom = null;
    }
}


// } Driver Code Ends
// User function Template for Java

class Solution {
    // Function to flatten a linked list

    Node mergeList(Node l1, Node l2){


        Node dummy = new Node(-1);
        Node temp = dummy;

        while (l1 != null && l2 != null) {
            if(l1.data <= l2.data){
                temp.bottom = l1;
                l1 = l1.bottom;
            }
            else{
                temp.bottom = l2;
                l2 = l2.bottom;
            }
            temp = temp.bottom;
        }

        if(l1 != null){
            temp.bottom = l1;
        }
        if(l2 != null){
            temp.bottom = l2;
        }

        return dummy.bottom;
    }
    // using loop
    Node flatten(Node root) {
        
        Node dummy = new Node(-1);
        Node temp = dummy;
        if(root.next == null){
            return root;
        }
        while (root != null) {
            if(temp == dummy){
                temp= mergeList(root, root.next);
                root = root.next.next;
            }
            else{
                temp = mergeList(temp, root);
                root = root.next;
            }
        }

        return temp;
    }

    // using recursion
    Node flatten2(Node root){
        if(root == null || root.next == null){
            return root;
        }

        Node mergedHead = flatten2(root.next);

        return mergeList(root, mergedHead);
    }
}