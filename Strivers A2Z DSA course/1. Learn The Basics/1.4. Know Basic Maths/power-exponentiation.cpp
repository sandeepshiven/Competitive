#include<bits/stdc++.h>
using namespace std;

int main(){
  
    int n,x;
    cin >> x >> n;
    cout << calculatePower(x, n);

    return 0;
}


long long calculatePower(int x, int n){

    long long ans = 1;

    while(n){

        if(n%2 != 0){
            ans *= x;
            n--;
        }
        else{
            x *= x;
            n = n/2;
        }

    }

    return ans;

}
/*

example - find 3^9

x = 3, n=9, ans=1

n=odd, x=3, n=8, ans=1*3
n=even, x=9, n=4, ans = 3;
n=even, x=81, n=2, ans=3;
n=even, x=6561, n=1, ans = 3;
n=odd, x=6561, n=0, ans = 1*3*6561;

ans is returned


*/