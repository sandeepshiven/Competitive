#include<bits/stdc++.h>
using namespace std;

void moveZeroes1(vector<int>& arr) {
    int n = arr.size();
    int j = -1;
    for (int i = 0; i < n; i++) { // finding the first 0
        if (arr[i] == 0) {
            j = i;
            break;
        }
    }
    if (j == -1) { // if no zero then return
        return;
    }
    for (int i = j + 1; i < n && j < n; i++) { // start from next index of first zero and swap the non zero
        // by doing this j will always point to a zero
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

void moveZeroes2(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0, j = 0; i < n && j < n; i++) {
        if (arr[i] == 0) { // i'th element is zero
            if (j == 0) {
                j = i + 1;
            }
            while (j < n && arr[j] == 0) j++; // iterate the whole zeros chunk until non zero
            if (j == n) {
                break;
            }
            swap(arr[i], arr[j]); // now i'th zero and j'th non-zero is swapped
        }
    }
}

int main() {



    return 0;
}