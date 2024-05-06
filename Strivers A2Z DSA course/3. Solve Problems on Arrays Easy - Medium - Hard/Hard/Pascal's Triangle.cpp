#include<bits/stdc++.h>
using namespace std;

int main(){
  
    

    return 0;
}

/*

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]

https://leetcode.com/problems/pascals-triangle/

*/


class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>>res;
        res.push_back({1});
        if(numRows >= 2){
            res.push_back({1, 1});
        }
        for(int i = 3; i<=numRows; i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j=0; j<res.back().size()-1; j++){
                temp.push_back(res.back()[j] + res.back()[j+1]);
            }
            temp.push_back(1);
            res.push_back(temp);
        }
        return res;

    }

    vector<int> generateRow(int row){
        vector<int> res;
        res.push_back(1);
        int ans = 1;
        for(int col = 1; col<row; col++){
            ans *= (row-col);
            ans /= col;
            res.push_back(ans);
        }
        return res;        

    }

    vector<vector<int>> generate1(int numRows) {

        vector<vector<int>>res;
        for(int row = 1; row <= numRows; row++){
            res.push_back(generateRow(row));
        }
        return res;

    }
};