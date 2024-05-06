#include<bits/stdc++.h>
using namespace std;

int main(){
  
    

    return 0;
}
/*

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

https://leetcode.com/problems/merge-intervals/

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        vector<vector<int>>res;

        sort(intervals.begin(), intervals.end());

        for(int i=0; i<n; ){
            int j = i+1;
            int start = intervals[i][0];
            int end = intervals[i][1];
            while(j<n && end >= intervals[j][0] ){
                if(end < intervals[j][i]){
                    end = intervals[j][i];
                }
                j++;
            }

            res.push_back({start, end});
            i = j;
        }

        return res;


    }
};