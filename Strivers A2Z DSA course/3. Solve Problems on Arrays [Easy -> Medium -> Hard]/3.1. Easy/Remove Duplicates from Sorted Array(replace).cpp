#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (nums[j] != nums[i]) { // as j is one less than i if element is unique the [j+1] copy
                                // will have no effect
            nums[j + 1] = nums[i]; // but if there are same elements x then the next different element y will be copied in x+1 th position and j will increase.
            j++;
        }

    }
    return j + 1;
}

int main() {



    return 0;
}