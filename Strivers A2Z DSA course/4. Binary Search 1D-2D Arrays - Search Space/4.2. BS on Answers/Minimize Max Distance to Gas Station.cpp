#include<bits/stdc++.h>
using namespace std;

int main() {



    return 0;
}

/*

We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where n = size of the stations array. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. Find the answer exactly to 2 decimal places.

Example 1:

Input:
n = 10
stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
k = 9
Output: 0.50
Explanation: Each of the 9 stations can be added mid way between all the existing adjacent stations.
Example 2:

Input:
n = 10
stations = [3,6,12,19,33,44,67,72,89,95]
k = 2
Output: 14.00
Explanation: Construction of gas stations at 8th(between 72 and 89) and 6th(between 44 and 67) locations.


Your Task:
You don't need to read input or print anything. Your task is to complete the function findSmallestMaxDist() which takes a list of stations and integer k as inputs and returns the smallest possible value of d. Find the answer exactly to 2 decimal places.

https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1

*/

class Solution {
public:
    // brute force  - mine

    int findLargestGap(vector<int>& stations, vector<int>& gaps) {

        int idx = 0;
        double maxGap = -1.0;
        int n = stations.size();

        for (int i = 0; i < n - 1; i++) {

            double gap = double(stations[i + 1] - stations[i]) / double(gaps[i] + 1);
            if (gap > maxGap) {
                maxGap = gap;
                idx = i;
            }

        }
        return idx;
    }

    double findSmallestMaxDist(vector<int>& stations, int k) {

        int n = stations.size();
        vector<int>gaps(n - 1, 0);

        for (int i = 1; i <= k; i++) {
            int gapIdx = findLargestGap(stations, gaps);
            gaps[gapIdx]++;
        }

        int gapIdx = findLargestGap(stations, gaps);
        double maxGap = double(stations[gapIdx + 1] - stations[gapIdx]) / double(gaps[gapIdx] + 1);
        return maxGap;

    }
};


class Solution2 {
public:
    // using max heap

    

    double findSmallestMaxDist(vector<int>& stations, int k) {

        int n = stations.size();
        vector<int>gaps(n - 1, 0);
        priority_queue<pair<long double, int>>pq;
        for(int i=0; i<n-1; i++){
            pq.push({stations[i+1]-stations[i], i});
        }

        for (int i = 1; i <= k; i++) {
            pair<long double, int>gapPair = pq.top();
            pq.pop();
            gaps[gapPair.second]++;
            long double stationGap = (stations[gapPair.second + 1] - stations[gapPair.second])/(long double)(gaps[gapPair.second] + 1);
            pq.push({stationGap, gapPair.second});

        }

        
        return pq.top().first;

    }
};


class Solution2 {
public:
    // using binary search   
    int findStaions(vector<int>& stations, long double dist){
        int count = 0;
        int n = stations.size();
        for(int i = 0; i<n-1; i++){
            // this gets the stations between eg if gap is 1 and dist is 0.4 then 1/0.4 will be 2.xyz so we can fit 2 staions there
            int stationsBetween = (stations[i+1] - stations[i])/dist;
            // for cases like 1/0.5 = 2 but in reality we can only fit 1 station
            if((stations[i+1] - stations[i]) == stationsBetween * dist){
                stationsBetween--;
            }
            count += stationsBetween;
        }
        return count;
    }
    double findSmallestMaxDist(vector<int>& stations, int k) {

        int n = stations.size();
        long double low = 0, high = 0, ans;

        for(int i=0; i<n-1; i++){
            high = max((int)high, stations[i+1] - stations[i]);
        }
        long double limit = 1e-6;
        while(high - low > limit){
            long double mid = low + (high - low)/2;
            int cnt = findStaions(stations, mid);
            if(cnt > k){
                low = mid;
            }
            else{
                ans = mid;
                high = mid;
            }

        }
        

        
        return ans;

    }
};