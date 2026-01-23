#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define Hosam ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const ll oo = 1e9, N = 1e6, MOD = 1e9 + 7;
const ld PI = acos(-1.0L), EPS = 1e-9;

ll XorFrom0ToN(ll n){
    if (n % 4 == 0) return n; 
    if (n % 4 == 1) return 1; 
    if (n % 4 == 2) return n + 1;
    return 0; 
}
void solve(){
    ll n, q; cin >> n; 
    cout << XorFrom0ToN(n) << endl; 
}

int main(){
    Hosam;
    ll t; cin >> t;
    while(t--){ solve(); }
    return 0;
}
