#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define Hosam ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const ll oo = 1e9, N = 1e6, MOD = 1e9 + 7;
const ld PI = acos(-1.0L), EPS = 1e-9;

const pair<ll, ll> adj[]{
    {-1 ,0},
    {0 ,+1}, 
    {+1 ,0},
    {0 ,-1}
}; 

void solve(){
    ll n, m; cin >> n >> m; 
    vector<string>v(n); 
    vector<vector<ll>> vis(n, vector<ll>(m, -1)); 
    for(auto &c : v){ cin >> c; }

    auto in = [&](ll x, ll y) -> bool {
        return x >= 0 && x < n && y >= 0 && y < m && v[x][y] != '#' && vis[x][y] == -1; 
    }; 

    // imp BFS
    ll cnt = 0; 
    auto BFS =[&](ll sx, ll sy){
        queue<pair<ll, ll>> q; 
        q.emplace(sx, sy); 
        vis[sx][sy] = cnt; 
        while (q.size()){
            ll r = q.front().first, c = q.front().second; 
            q.pop(); 
            for(auto d : adj){
                r += d.first, c += d.second; 
                if(!in(r, c)) continue;
                q.emplace(r, c); 
                vis[r][c] = cnt;
            }
        }
    }; 

    for(ll i = 0; i < n ;i++){
        for(ll j = 0; j < m ;j++){
            if(in(i, j)){
                BFS(i, j); 
                cnt++; 
            }
        }
    }

    ll q; cin >> q; 
    while (q--){
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2; 
        if(vis[x1][y1] == vis[x2][y2]){
            cout << "YES\n"; 
        }else { 
            cout << "NO\n"; 
        }
    }
    
}

int main(){
    Hosam;
    solve();
    return 0;
}
