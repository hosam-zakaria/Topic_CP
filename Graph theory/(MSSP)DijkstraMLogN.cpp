#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e3 + 4, M = 2e5 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;

ll n, m;

ll head[N], to[M], cost[M], nxt[M], ne;

void init(){
    memset(head, -1, sizeof head);
    ne = 0;
}

void addEdge(ll f, ll t, ll c){
    to[ne] = t;
    cost[ne] = c;
    nxt[ne] = head[f];
    head[f] = ne++;
}

void addBiEdge(ll a, ll b, ll c){
    addEdge(a, b, c);
    addEdge(b, a, c);
}


ll dist[N][N];
/// Time Complexity: O(M log N)
void DijkstraMLogN(ll src){
    for(ll i = 0; i < n; ++i)
        dist[src][i] = INT_MAX;
    dist[src][src] = 0;

    /// pair -> dist, node_id
    priority_queue<pair<ll, ll>> PQ;
    PQ.emplace(0, src);
    while(PQ.size()){
        ll u = PQ.top().second;
        ll d = -PQ.top().first;
        PQ.pop();
        if(d != dist[src][u]) continue;
        for(ll e = head[u]; ~e; e = nxt[e]){
            ll v = to[e], c = cost[e];
            ll dd = d + c;
            if(dd < dist[src][v]){
                dist[src][v] = dd;
                PQ.emplace(-dd, v);
            }
        }
    }
}

/// Time Complexity: O(NM Log N)
void preProcess(){
    for(ll i = 0; i < n; ++i)
        DijkstraMLogN(i);
}

int main(){
    cin >> n >> m;
    init();
    for(ll i = 0; i < m; ++i){
        ll u, v, c;
        cin >> u >> v >> c;
        addBiEdge(u, v, c);
    }

    ll q;
    cin >> q;
    preProcess();
    while(q--){
        ll u, v;
        cin >> u >> v;
        cout << dist[u][v] << '\n';
    }
}
/*
6 8
0 1 10
0 2 1
2 1 2
2 3 15
2 4 2
3 4 3
1 5 3
4 5 1
10
*/

