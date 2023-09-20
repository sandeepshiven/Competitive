#include<bits/stdc++.h>
using namespace std;

void rotate1(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // if k == n then rotated array will same as original so we need only remaining rotations
    for (int i = n - k - 1; i >= 0; i--) { // n-k-1 is last element in first half of the array to be shifted
        //then we need to shift this element to k places and repeat till the first element
        int temp = k;
        int j = i;
        while (temp--) {
            swap(nums[j], nums[j + 1]);
            j++;
        }
    }

}

void rotate2(vector<int>& nums, int k) {


    int n = nums.size();
    k = k % n;
    //                    copying the first half             copying the second half
    vector<int>arr1(nums.begin(), nums.begin() + (n - k)), arr2(nums.begin() + (n - k), nums.end());
    int j = 0;
    // copying back to original
    for (auto i : arr2) {
        nums[j] = i;
        j++;
    }

    for (auto i : arr1) {
        nums[j] = i;
        j++;
    }



}

void rotate3(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    // trick or observation
    reverse(nums.begin(), nums.begin() + (n - k));
    reverse(nums.begin() + (n - k), nums.end());
    reverse(nums.begin(), nums.end());
}

int main() {



    return 0;
}