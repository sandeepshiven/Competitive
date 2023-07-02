/*

Problem Statement
Detailed explanation ( Input/output format, Notes, Constraints, Images )
Sample Input 1 :
7
Sample Output 1 :
 true
Sample Input 2 :
15
Sample Output 2 :
 false

 https://www.codingninjas.com/codestudio/problems/check-prime_624674?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTab=0

*/

#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int n; 
	cin >> n;
	for(int i=2; i*i <= n; i++){
		if(n%i == 0){
			cout << "false";
			return 0;
		}
	}
	cout << "true";
	return 0;
}
