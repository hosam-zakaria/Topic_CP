#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define Hosam ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const ll oo = 1e9, N = 1e3 + 5, MOD = 1e9 + 7;
const ld PI = acos(-1.0L), EPS = 1e-9;

ll n, m; 

ll adjMat[N][N], dist[N][N], notVis[N]; 
void DijkstraN2(ll src){
    iota(notVis , notVis + n, 0); 
    ll sz = n, nxt = notVis[src]; 
    for(ll i = 0; i < n ; i++){
        dist[src][i] = INT_MAX; 
    }
    dist[src][src] = 0;
    do{
        // Best Candidate
        ll u = notVis[nxt]; 

        // remove from notVis
        notVis[nxt] = notVis[--sz]; 

        // clac Best nxt Candidate
        nxt = -1;
        ll best = INT_MAX;
        for(ll i = 0; i < sz; ++i){
            ll v = notVis[i];
            ll d = dist[src][u] + adjMat[u][v];
            if(d < dist[src][v])
                dist[src][v] = d;

            if(dist[src][v] < best){
                best = dist[src][v];
                nxt = i;
            }
        }
    }while (nxt != -1); 
}
/// Time Complexity: O(N^3)
void preProcess(){
    for(ll i = 0; i < n; ++i)
        DijkstraN2(i);
}

void solve(){
    cin >> n >> m;
    
    // clear adj Matrix 
    for(ll i = 0; i < n ;i++){
        for(ll j = 0; j < n ; j++){
            adjMat[i][j] = INT_MAX;
        }
    }

    // input src , dest , cost 
    for(ll i = 0; i < m ;i++){
        ll u, v, c; 
        cin >> u >> v >> c; 
        adjMat[u][v] = c; 
        adjMat[v][u] = c; 
    }

    preProcess(); 
    // answer of query O(1)
    ll q; 
    cin >> q; 
    while (q--){
        ll u, v; 
        cin >> u >> v; 

        cout << dist[u][v] << endl; 
    }

}

int main(){
    Hosam;
    solve();
    return 0;
}
