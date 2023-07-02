#include<bits/stdc++.h>

using namespace std;

int main(){

    vector<long long> d{1, 2,3, 4,5 };
    cout << d.size() << '\n';
    cout << d.capacity() << '\n';
    d.push_back(6);
    cout << d.size() << '\n';
    cout << d.capacity() << '\n';
    cout << d.max_size() << '\n';
    
    
    return 0;
}