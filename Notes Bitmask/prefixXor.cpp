#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define Hosam ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const ll oo = 1e9, N = 1e6, MOD = 1e9 + 7;
const ld PI = acos(-1.0L), EPS = 1e-9;

void solve(){
    ll n, q; cin >> n; 
    vector<ll> v(n), perfix(n); 
    for(auto &c : v) { cin >> c; }

    for(ll i = 0; i < n ;i++){ 
        perfix[i] = (i? perfix[i - 1] ^ v[i] : v[i]); 
    }

    cin >> q; 
    while (q--){
        ll l, r; cin >> l >> r; // l = 2  r = 4  
        // cout << (5 ^ 7 ^ 9) << endl; 
        cout << (perfix[r] ^ perfix[l - 1]) << endl; // 11
    }
    
}

int main(){
    Hosam;
    ll t; cin >> t;
    while(t--){ solve(); }
    return 0;
}
