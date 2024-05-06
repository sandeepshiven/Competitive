#include<bits/stdc++.h>
using namespace std;

int main(){
  
    

    return 0;
}

/*

ou are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

*/


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();

        // reversing the rows
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }

        // reversing the lower triangle, diagonal is included
        for(int i=0; i<n; i++){
            int rowUp = i;
            int colUp = 0;
            int rowDown = n-1;
            int colDown = n-i-1;
            while(rowUp < rowDown){
                swap(matrix[rowUp][colUp], matrix[rowDown][colDown]);
                rowUp++, colUp++;
                rowDown--, colDown--;
            }
        }        

        // reversing the upper triangle
        for(int i=1; i<n; i++){
            int rowUp = 0;
            int colUp = i;
            int rowDown = n-1-i;
            int colDown = n-1;
            while(rowUp < rowDown){
                swap(matrix[rowUp][colUp], matrix[rowDown][colDown]);
                rowUp++, colUp++;
                rowDown--, colDown--;
            }
        } 

    }


    void rotate1(vector<vector<int>>& matrix) {
        
        int n = matrix.size();


        // Transposing the matrix
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }     

        
        // reversing the rows
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }   

         

    }
};






