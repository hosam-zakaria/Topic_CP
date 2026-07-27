#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define Hosam ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const ll oo = 1e9, N = 1e6, MOD = 1e9 + 7;
const ld PI = acos(-1.0L), EPS = 1e-9;


struct DSU{
    ll cnt;
    vector<ll> p, sz;
    DSU(ll n): cnt(n), p(n + 1), sz(n + 1, 1) {
        iota(p.begin(), p.end(), 0);
    }
    ll find(ll u) {
        return p[u] = u == p[u]? u : find(p[u]);
    }
    bool same(ll u, ll v) { return find(u) == find(v); }
    bool merge(ll u, ll v) {
        ll uP = find(u), vP = find(v);
        if(vP == uP) return false;
        if(sz[vP] > sz[uP]) swap(uP, vP);
        sz[uP] += sz[vP], p[vP] = uP, cnt--;
        return true;
    }
};
void solve(){
    ll n, m;
    cin >> n >> m;

    DSU dsu(n + 27);
    map<string , ll> mp; 
    for(ll i = 0; i < n; i++){
        string s; 
        cin >> s; 

        mp[s] = i; 
        for(char &c : s){
            dsu.merge(c - 'a', i + 26);
        }
    }   

    while(m--){
        string a, b; 
        cin >> a >> b;

        cout << (dsu.same(mp[a] + 26, mp[b] + 26)? "LUA" : "RYEI") << endl; 
    }
}

int main(){
    Hosam;
    solve();
    return 0;
}
