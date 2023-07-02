
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define null NULL


typedef long double ld;

#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

#define vc vector
#define pb push_back
#define um unordered_map
#define us unordered_set
#define inf (int)((1e6)+5)
#define MOD (int)((1e9)+7)

vc<int>primes;


void spfSeive(int n){

    vc<bool>isPrime(n+1, true);
    vc<int>spf(n+1);
    isPrime[1] = false;     
    isPrime[0] = false;

    for(int i = 2; i<= n; i++){
        if(isPrime[i]){
            primes.push_back(i);
            spf[i] = i;
        }
        for(int j = 0; j<(int)primes.size() &&
                        i*primes[j]<n && primes[j]<=spf[i];
                        j++){

            isPrime[i*primes[j]] = false;
            spf[i*primes[j]] = primes[j];

        }
    }
    
}

void simpleSeive(int n){
    primes = vc<int>(n+1, 1);
    primes[0] = 0;
    primes[1] = 0;
    for(int i=2; i*i <=n; i++){
        if(primes[i]){
            for(int j = i*i; j<=n; j += i){
                primes[j] = 0;
            }
        }
    }
}


bool myComp(pair<string, int>a, pair<string, int>b){
    return a.second < b.second;    
}

int gcd(int a, int b){
    if(a==0){
        return b;
    }
    return gcd(b%a, a);
}

int mod(int a, int m){
    return (a%m + m) % m;
}

int power(int x, int n, int m){

    int res = 1;

    x = x%m;
    if(x==0){
        return 0;
    }

    while(n){
        if(n%2 == 1){
            res = (res*x)%m;
        }
        x = (x*x)%m;
        n /= 2;
    }
    return res;

}
int nCr(int n, int r){

    int p=1, k=1;

    if(n-r < r){
        r = n-r;
    }

    if(r != 0){

        while(r){
            
            p *= n;
            k *= r;

            int m = gcd(p, k);

            p /= m;
            k /= m;
            n--;
            r--;

        }

    }
    else{
        p=1;
    }
    return p;

}

int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        
    int n = vals.size();

    if(k == 0){
        return *max_element(vals.begin(), vals.end());
    }


    vector<vector<int>>graph(n);
        
    for(vector<int> v: edges){
        graph[v[0]].push_back(vals[v[1]]);
        graph[v[1]].push_back(vals[v[0]]);
    }
        
    int res = INT_MIN;
        
    int x = 0;
    for(auto v: graph){
        sort(v.begin(), v.end());

        // for(auto x: v){
        //     cout << x << ", ";
        // }
        

        int v_n = v.size();
        int temp = vals[x];
        for(int i = 0; i<v.size() && i<k; i++){
            if(temp+v[v_n - 1 - i] > temp){

                temp += v[v_n - 1 - i];
            }
        }
        res = max(res, temp);
        // cout <<"temp: " << temp <<  '\n';
        x++;
            
    }
        
    return res; 

}

void testcase(){


    int n;
    cin >> n;
    vector<int>vals(n);
    for(int i=0; i<n; i++){
        cin >> vals[i];
    }
    int e;
    cin >> e;
    vector<vector<int>>edges(e, vector<int>(2));
    for(int i=0; i<e; i++){
        cin >> edges[i][0] >> edges[i][1]; 
    }
    int k;
    cin >> k;

    cout << maxStarSum(vals, edges, k);
    

    cout << '\n';
    
}


signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(null);
    cout.tie(null);
    //generatePrimes(1000001);
    
    int t;
    
    
   // cin >> t;

       
   // while(t--){
        
        testcase();
		

   // }
    
    return 0;
}

