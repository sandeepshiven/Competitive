import java.util.*;

public class CopyListWithRandomPointer {

}

/*
 * A linked list of length n is given such that each node contains an additional
 * random pointer, which could point to any node in the list, or null.
 * 
 * Construct a deep copy of the list. The deep copy should consist of exactly n
 * brand new nodes, where each new node has its value set to the value of its
 * corresponding original node. Both the next and random pointer of the new
 * nodes should point to new nodes in the copied list such that the pointers in
 * the original list and copied list represent the same list state. None of the
 * pointers in the new list should point to nodes in the original list.
 * 
 * For example, if there are two nodes X and Y in the original list, where
 * X.random --> Y, then for the corresponding two nodes x and y in the copied
 * list, x.random --> y.
 * 
 * Return the head of the copied linked list.
 * 
 * The linked list is represented in the input/output as a list of n nodes. Each
 * node is represented as a pair of [val, random_index] where:
 * 
 * val: an integer representing Node.val
 * random_index: the index of the node (range from 0 to n-1) that the random
 * pointer points to, or null if it does not point to any node.
 * Your code will only be given the head of the original linked list.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * Example 2:
 * 
 * 
 * Input: head = [[1,1],[2,1]]
 * Output: [[1,1],[2,1]]
 * Example 3:
 * 
 * 
 * 
 * Input: head = [[3,null],[3,0],[3,null]]
 * Output: [[3,null],[3,0],[3,null]]
 * 
 * 
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 */

class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }

}

class Solution {

    // using hashmap
    public Node copyRandomList(Node head) {

        Map<Node, Node> mp = new HashMap<>();

        Node temp = head;

        while (temp != null) {
            Node newNode = new Node(temp.val);
            mp.put(temp, newNode);
            temp = temp.next;
        }

        for (Map.Entry<Node, Node> entry : mp.entrySet()) {
            Node newNode = entry.getValue();
            Node oldNode = entry.getKey();
            newNode.next = mp.get(oldNode.next);
            newNode.random = mp.get(oldNode.random);
        }

        return mp.get(head);
    }

    // without using extra space;
    public Node copyRandomList2(Node head) {

        Node temp = head;

        // inserting new nodes in between
        while (temp != null) {

            Node newNode = new Node(temp.val);
            newNode.next = temp.next;
            temp.next = newNode;
            temp = temp.next.next;

        }

        // copying random pointers
        temp = head;
        while(temp != null){
            Node newNode = temp.next;
            Node randomNode = temp.random;
            if(randomNode == null){
                newNode.random = null;
            }
            else{
                newNode.random = randomNode.next;
            }
            temp = temp.next.next;
        }

        // copying next pointers
        Node dummy = new Node(-1);
        Node res = dummy;
        Node prev = null;
        temp = head;
        while(temp != null){
            res.next = temp.next;
            temp.next = temp.next.next;
            res = res.next;
            temp = temp.next;
        }   


        return dummy.next;
    }
}