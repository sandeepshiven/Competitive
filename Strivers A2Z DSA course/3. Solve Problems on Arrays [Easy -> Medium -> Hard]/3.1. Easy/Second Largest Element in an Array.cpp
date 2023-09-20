#include<bits/stdc++.h>
using namespace std;


vector<int> getSecondOrderElements(int n, vector<int> a) {
    int max = a[0], min = a[0];
    int secMax = INT_MIN, secMin = INT_MAX;

    for(auto i: a){
        if(i > max){
            secMax = max;
            max = i;
        }
        else if(i < max && i > secMax){
            secMax = i;
        }

        if(i < min){
            secMin = min;
            min = i;
        }
        else if(i > min && i < secMin){
            secMin = i;
        }
    }  
    return vector<int>{secMax, secMin};

}



int main(){
  
    

    return 0;
}