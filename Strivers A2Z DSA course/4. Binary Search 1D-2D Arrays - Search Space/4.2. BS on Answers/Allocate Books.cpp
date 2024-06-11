#include<bits/stdc++.h>
using namespace std;

int main(){
  
    

    return 0;
}

/*
Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.



There are ‘m’ number of students, and the task is to allocate all the books to the students.



Allocate books in such a way that:

1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.


You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.



If the allocation of books is not possible, return -1.



Example:
Input: ‘n’ = 4 ‘m’ = 2 
‘arr’ = [12, 34, 67, 90]

Output: 113

Explanation: All possible ways to allocate the ‘4’ books to '2' students are:

12 | 34, 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12’, and student two is ‘34+ 67+ 90 = 191’, so the maximum is ‘max(12, 191)= 191’.

12, 34 | 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 = 46’, and student two is ‘67+ 90 = 157’, so the maximum is ‘max(46, 157)= 157’.

12, 34, 67 | 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 +67 = 113’, and student two is ‘90’, so the maximum is ‘max(113, 90)= 113’.

We are getting the minimum in the last case.

Hence answer is ‘113’.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
4 2
12 34 67 90
Sample Output 1:
113
Explanation of sample input 1:
All possible ways to allocate the ‘4’ books to '2' students are:

12 | 34, 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12’, and student two is ‘34+ 67+ 90 = 191’, so the maximum is ‘max(12, 191)= 191’.

12, 34 | 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 = 46’, and student two is ‘67+ 90 = 157’, so the maximum is ‘max(46, 157)= 157’.

12, 34, 67 | 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 +67 = 113’, and student two is ‘90’, so the maximum is ‘max(113, 90)= 113’.

We are getting the minimum in the last case.

Hence answer is ‘113’.
Sample Input 2:
5 4
25 46 28 49 24
Sample Output 2:
71
Explanation of sample input 2:
All possible ways to allocate the ‘5’ books to '4' students are:

25 | 46 | 28 | 49 24 - the sum of all the pages of books allocated to students 1, 2, 3, and 4 are '25', '46', '28', and '73'. So the maximum is '73'.

25 | 46 | 28 49 | 24 - the sum of all the pages of books allocated to students 1, 2, 3, and 4 are '25', '46', '77', and '24'. So the maximum is '77'.

25 | 46 28 | 49 | 24 - the sum of all the pages of books allocated to students 1, 2, 3, and 4 are '25', '74', '49', and '24'. So the maximum is '74'.

25 46 | 28 | 49 | 24 - the sum of all the pages of books allocated to students 1, 2, 3, and 4 are '71', '28', '49', and '24'. So the maximum is '71'.

We are getting the minimum in the last case.

Hence answer is ‘71’.
https://www.naukri.com/code360/problems/allocate-books_1090540?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries

*/

int getAllocation(vector<int>& arr, int n, int maxPages){

    int currPages = 0, pages=-1, students=1;
    bool flag = true;
    for(int i=0; i<n; i++){
        // checking if one student get atleast this amount of pages
        if(arr[i] + currPages <= maxPages){
            currPages += arr[i];
        }
        else{
            students++;
            // pages = max(currPages, pages);
            currPages = arr[i];
        }
    }    

    return students;

}

int findPages(vector<int>& arr, int n, int m) {
    
    if(m > n){
        return -1;
    }

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = INT_MAX;

    while(low <= high){
        int mid = low + (high - low)/2;
        int students = getAllocation(arr, n, mid);
        if(students > m){
            
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    /*
    returning low instead of storing in ans because
    // 1. polarity reverse low was initially at a point where it was not possible and high was at a fairly possible point
    // 2. if we store ans if student == m then at some cases no. of students will not be
    equal to m and high will cross m for these cases low will be the answer as it is the
    least value on which every student will get book eg. 2,3,1,1,1,1,1 for 5 students
    
    */
    return low;    

}