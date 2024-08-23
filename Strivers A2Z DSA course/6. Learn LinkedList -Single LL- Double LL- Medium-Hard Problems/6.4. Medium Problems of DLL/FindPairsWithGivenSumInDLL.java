import java.util.*;
import java.lang.*;

public class FindPairsWithGivenSumInDLL {
    
}

/*
 * 
 * Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value target.

 

Example 1:

Input:  
1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
target = 7
Output: (1, 6), (2,5)
Explanation: We can see that there are two pairs 
(1, 6) and (2,5) with sum 7.
 

Example 2:

Input: 
1 <-> 5 <-> 6
target = 6
Output: (1,5)
Explanation: We can see that there is one pairs  (1, 5) with sum 6.

 

Your Task:
You don't need to read input or print anything. Your task is to complete the function findPairsWithGivenSum() which takes head node of the doubly linked list and an integer target as input parameter and returns an array of pairs. If there is no such pair return empty array.

https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-pairs-with-given-sum-in-doubly-linked-list
 */

 class Node
{
    int data;
    Node next,prev;
    
    Node(int x){
        data = x;
        next = null;
        prev = null;
    }
}

class Solution {
    public static ArrayList<ArrayList<Integer>> findPairsWithGivenSum(int target, Node head) {
        if(head == null || head.next == null){
            return new ArrayList<ArrayList<Integer>>();
        }

        Node start = head;
        Node temp = head;
        while(temp.next != null){
            temp = temp.next;
        }
        Node end = temp;

        ArrayList<ArrayList<Integer>> res = new ArrayList<>();

        while(start != end){
            if(start.data+end.data == target){
                ArrayList<Integer> temp1 = new ArrayList<>();
                temp1.add(start.data);
                temp1.add(end.data);
                res.add(temp1);
                start = start.next;
            }
            else if(start.data+end.data > target){
                end = end.prev;
            }
            else{
                start = start.next;
            }
        }
        return res;
    }
}