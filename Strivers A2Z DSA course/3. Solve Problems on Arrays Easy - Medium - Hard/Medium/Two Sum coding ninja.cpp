#include<bits/stdc++.h>
using namespace std;

int main(){
  
    

    return 0;
}


/*

Sam want to read exactly ‘TARGET’ number of pages.

He has an array ‘BOOK’ containing the number of pages for ‘N’ books.

Return YES/NO, if it is possible for him to read any 2 books and he can meet his ‘TARGET’ number of pages.

Example:
Input: ‘N’ = 5, ‘TARGET’ = 5
‘BOOK’ = [4, 1, 2, 3, 1] 

Output: YES
Explanation:
Sam can buy 4 pages book and 1 page book.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
5 5
4 1 2 3 1
Sample Output 1 :
YES
Explanation Of Sample Input 1:
Sam can buy 4 pages book and 1-page book.
Sample Input 2:
2 1
1 2
Sample Output 2 :
NO
Expected Time Complexity:
O( N ), Where N is the length of the array.

https://www.naukri.com/code360/problems/reading_6845742?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

*/

// using map
string read(int n, vector<int> book, int target)
{
    map<int, int>mp;
    for(auto i: book){
        mp[i]++;
    }
    for(auto i: book){
        if(mp.find(target - i) != mp.end()){
            if(target - i == i && mp[target -i] > 1){
                return "YES";
            }
            else{
                return "YES";
            }
        }
    }
    return "NO";
}


// using 2 pointers
string read1(int n, vector<int> book, int target)
{
    int i = 0, j= n-1;
    sort(book.begin(), book.end());
    while(i<j){
        if(book[i] + book[j] == target){
            return "YES";
        }
        else if(book[i] + book[j] < target){
            i++;
        }
        else{
            j--;
        }
    }
    return "NO";
}

