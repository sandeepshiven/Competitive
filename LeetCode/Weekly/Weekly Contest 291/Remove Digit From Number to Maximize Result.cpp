#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDigit(string number, char digit) {
        
        int idx = 0;
        int n = number.length();
        string res ="", temp;
        for(int i=0; i<n; i++){
            if(number[i] == digit){
                idx = i;
                temp = number.substr(0, idx) + number.substr(idx+1, n);
                if(temp > res){
                    res = temp;
                }
            }
        }

        return res;

    }
};

int main(){

    return 0;
}