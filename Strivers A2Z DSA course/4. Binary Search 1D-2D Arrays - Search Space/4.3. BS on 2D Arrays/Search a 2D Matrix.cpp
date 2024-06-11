#include<bits/stdc++.h>
using namespace std;

int main(){
  
    

    return 0;
}

/*

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false


https://leetcode.com/problems/search-a-2d-matrix/description/

*/

class Solution {
public:

// double binary search
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0, high = n-1, row = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(matrix[mid][0] <= target){
                row = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        if(row == -1){
            return false;
        }
        
        low = 0, high = m-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(matrix[row][mid] == target){
                return true;
            }
            else if(matrix[row][mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return false;

    }

    // single binary search with matrix flatenning logic
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0, high = (n*m) - 1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int row = mid/n;
            int col = mid%m;
            if(matrix[row][col] == target){
                return true;;
            }
            else if(matrix[row][col] < target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }   

        return false;int n = matrix.size();
        int m = matrix[0].size();

        int low = 0, high = (n*m) - 1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int row = mid/m; // as each row has m elements thus row num will be multiple of m if flattened
            int col = mid%m; // as each row has m elements thus col num will be reminder of m if flattened
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
                
            }
        }   

        return false;

    }
};


