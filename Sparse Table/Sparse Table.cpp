#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define Hosam ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const ll oo = 1e9, N = 1e6, MOD = 1e9 + 7;
const ld PI = acos(-1.0L), EPS = 1e-9;

vector<vector<ll>> sp; 

ll mrg(ll a, ll b){
    ll sum = a + b;
    return sum; 
}
void build(vector<ll> &v){
    const ll n = v.size(); 
    sp[0] = v; 
    
    for(ll mask = 1; (1 << mask) <= n; mask++){
        ll sz = 1 << mask; 
        for(ll i = 0; i + sz <= n ;i++){
            ll a = sp[mask - 1][i]; 
            ll b = sp[mask - 1][i + (1 << (mask - 1))];     
            sp[mask][i] = mrg(
                a, 
                b
            );
        }
    }
}
ll query(ll l, ll r){
    ll res = 0, len = r - l + 1;
    for(ll mask = 0; l <= r ;mask++){
        if(len >> mask & 1){
            res = mrg(sp[mask][l], res); 
            l += 1 << mask; 
        }
    }
    return res; 
}
void solve(){
    ll n, q; 
    cin >> n >> q;
    vector<ll>v(n); 
    for(auto &c : v) { cin >> c; }

    sp = vector<vector<ll>>(__lg(n) + 1, vector<ll>(n)); 
    build(v); 
    ll l, r; 
    while(q--){
        cin >> l >> r; 
        l--; 
        r--; 
        cout << query(l, r) << endl; 
    }
    
}

int main(){
    Hosam;
    solve();
    return 0;
}
