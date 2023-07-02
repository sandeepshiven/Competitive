/*

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

    a.) Integers in each row are sorted from left to right.
    b.) The first integer of each row is greater than the last integer of the previous row.


Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true


Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

https://leetcode.com/problems/search-a-2d-matrix/

*/








#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // Complexity O(log(n) + log(m))
        
        
        // as the last element of the previous row is smaller than first element of current row
        // if the value of first element of the row is smaller than target then that row becomes
        // a potential candidate to contain result if it is bigger then all elements in right
        // will also be bigger thats why we are taking smaller element row as candidate
        // first we will find the candidate row by using binary search on first column of matrix 
        
        int n = matrix.size();
        int m = matrix[0].size();

        int l=0, r=n, mid, row=0;
        while(l < r){
            
            mid = (l+r)/2;

            if(matrix[mid][0] <= target){
                l = m+1;
                row = mid;
            }
            else{
                r = mid-1;
            }

        }

        // after getting the candidate row we are using binary search on the row.

        l=0, r = m, mid=0;
        
        while(l < r){

            mid = (l+r)/2;

            if(matrix[row][mid] == target){
                return true;
            }
            else if(matrix[row][mid] > target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return false;

    }
};