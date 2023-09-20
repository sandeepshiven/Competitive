#include<bits/stdc++.h>
using namespace std;

int main(){
  
    

    return 0;
}

vector < int > sortedArray(vector < int > a, vector < int > b) {
    vector<int> res;
    int n = a.size();
    int m = b.size();
    int i, j;
    for(i=0, j=0; i<n && j<m;){
        if(a[i] <= b[j]){
            if(res.size() == 0 || res.back() != a[i]){
                res.push_back(a[i]);            
            }
            i++;
        }
        else if(b[j] < a[i]){
            if(res.size() ==0 || res.back() != b[j]){
                res.push_back(b[j]);            
            };
            j++;
        }
        
    }
    while(i<n){
        if(res.back() != a[i]){
            res.push_back(a[i]);
        }
        i++;
    }

    while(j<m){
        if(res.back() != b[j]){
            res.push_back(b[j]);
        }
        j++;
    }
    return res;
}