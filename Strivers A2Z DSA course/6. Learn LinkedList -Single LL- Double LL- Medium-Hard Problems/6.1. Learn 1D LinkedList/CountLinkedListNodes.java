public class CountLinkedListNodes {
    
}

/*Given a singly linked list. The task is to find the length of the linked list, where length is defined as the number of nodes in the linked list.

Example 1:

Input:
LinkedList: 1->2->3->4->5
Output: 5
Explanation: Count of nodes in the 
linked list is 5, which is its length.
Example 2:

Input:
LinkedList: 2->4->6->7->5->1->0
Output: 7
Explanation: Count of nodes in the
linked list is 7. Hence, the output
is 7.
Your Task:
Your task is to complete the given function getCount(), which takes a head reference as an argument and should return the length of the linked list.
https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=count-nodes-of-linked-list

*/

class Node{
    int data;
    Node next;
    Node(int a){  data = a; next = null; }
}

class Solution
{
    //Function to count nodes of a linked list.
    public static int getCount(Node head)
    {
        
        int res = 0;
        while(head != null){
            res++;
            head = head.next;
        }
        return res;
    }
}
