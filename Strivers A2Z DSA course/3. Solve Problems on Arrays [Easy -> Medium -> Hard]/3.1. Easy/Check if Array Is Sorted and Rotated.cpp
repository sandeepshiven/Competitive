#include<bits/stdc++.h>
using namespace std;

bool check1(vector<int>& arr) {

    int n = arr.size();
    int i;
    for (i = 0; i < n - 1; i++) {
        // if any element is out of order then break
        if (arr[i] > arr[i + 1]) {
            break;
        }
    }
    // if i has reached n-1 then the whole array is in sorted order
    if (i == n - 1) {
        return true;
    }
    i++; // this is the break point from previous loop

    // checking if next part of the array is in order or not
    for (; i < n - 1; i++) {
        // if any element is out of order then return as the previous part was in order
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }

    // if above loop goes fine then check last and first elements as they are connected
    if (arr[n - 1] > arr[0]) {
        return false;
    }
    return true;

}

bool check2(vector<int>& arr) {

    int n = arr.size();
    int check = 0;
    for (int i = 0; i < n - 1; i++) {
        // if any element is out of order
        if (arr[i] > arr[i + 1]) {
            check++;
        }
    }
    // no element is out of order
    if (check == 0) {
        return true;
    }

    // out of element can appear atmost 1 time and also last and first elements are connected
    if (check > 1 || arr[n - 1] > arr[0]) {
        return false;
    }
    return true;

}

bool check3(vector<int>& arr) {

    int n = arr.size();
    int check = 0;
    for (int i = 0; i < n; i++) {
        // this will check first and last element also
        if (arr[i] > arr[(i + 1) % n]) {
            check++;
        }

        // atmost one element can be out of order
        if (check > 1) {
            return false;
        }
    }
    return true;

}


int main() {


    return 0;
}