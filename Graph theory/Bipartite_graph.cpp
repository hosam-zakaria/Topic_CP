#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define Hosam ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const ll oo = 1e9, N = 2e3 + 5, MOD = 1e9 + 7;
const ld PI = acos(-1.0L), EPS = 1e-9;
vector<ll>adj[N]; 
bool used[N], flag = false; 
ll color[N];
void DFS(ll node){
    for(auto c : adj[node]){
        if(color[c] == -1){
            color[c] = color[node] ^ 1;
            DFS(c);
        }else if(color[c] == color[node]){
            flag = true;
        }
    }
}
void solve(ll x, ll t){
    ll n ,m; cin >> n >> m; 
    for(ll i = 1; i <= n ;i++){
        adj[i].clear();
        color[i] = -1;
    }
    for(ll i = 0, a, b; i < m; i++){
        cin >> a >> b; 
        adj[a].emplace_back(b); 
        adj[b].emplace_back(a); 
    }
    flag = false;
    for(ll i = 1; i <= n ;i++){
        if(color[i] == -1) {color[i] = 0;  DFS(i);} 
        if(flag){
            cout << "Scenario " << "#" << x  - t << ":" << endl; 
            cout << "Suspicious bugs found!" << endl; 
            return; 
        }
    }
    cout << "Scenario " << "#" << x  - t << ":" << endl; 
    cout << "No suspicious bugs found!" << endl; 
}

int main(){
    Hosam;
    ll t, x; cin >> t;
    x = t; 
    while(t--){ solve(x, t); }
    return 0;
}
