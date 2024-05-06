#include<bits/stdc++.h>
using namespace std;

int main() {



    return 0;
}

/*

Given an m x n matrix, return all elements of the matrix in spiral order.



Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

https://leetcode.com/problems/spiral-matrix/description/

*/


class Solution {
public:

    // long
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>res;

        int rowStart = 0, colStart = 0, rowEnd = n - 1, colEnd = m - 1;
        while (rowStart < rowEnd && colStart < colEnd) {
            for (int i = colStart; i <= colEnd; i++) {
                res.push_back(matrix[rowStart][i]);
            }
            for (int i = rowStart + 1; i <= rowEnd; i++) {
                res.push_back(matrix[i][colEnd]);
            }
            for (int i = colEnd - 1; i >= colStart; i--) {
                res.push_back(matrix[rowEnd][i]);
            }
            for (int i = rowEnd - 1; i >= rowStart + 1; i--) {
                res.push_back(matrix[i][colStart]);
            }

            rowStart++, colStart++;
            rowEnd--, colEnd--;
        }
        if (rowStart == rowEnd) {
            for (int i = colStart; i <= colEnd; i++) {
                res.push_back(matrix[rowStart][i]);
            }
        }
        else if (colStart == colEnd) {
            for (int i = rowStart; i <= rowEnd; i++) {
                res.push_back(matrix[i][colStart]);
            }
        }
        return res;

    }

    // consice
    vector<int> spiralOrder1(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>res;

        int rowStart = 0, colStart = 0, rowEnd = n - 1, colEnd = m - 1;
        while (rowStart <= rowEnd && colStart <= colEnd) {

            for (int i = colStart; i <= colEnd; i++) {
                res.push_back(matrix[rowStart][i]);
            }
            rowStart++;

            for (int i = rowStart; i <= rowEnd; i++) {
                res.push_back(matrix[i][colEnd]);
            }
            colEnd--;

            if (rowStart <= rowEnd) {
                for (int i = colEnd; i >= colStart; i--) {
                    res.push_back(matrix[rowEnd][i]);
                }
            }
            rowEnd--;

            if (colStart <= colEnd) {
                for (int i = rowEnd ; i >= rowStart ; i--) {
                    res.push_back(matrix[i][colStart]);
                }
            }
            colStart++;
            
        }
       
        return res;

    }


};