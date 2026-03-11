#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e3 + 4, M = 2e5 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;

ll n, m;

ll dist[N][N];
/// Time Complexity: O(N^3)
void floyd(){
    for(int k = 0; k < n; ++k)
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}



int main(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            dist[i][j] = INT_MAX;
            if(i == j) dist[i][j]
        }
    }

    for(ll i = 0; i < m; ++i){
        ll u, v, c;
        cin >> u >> v >> c;
        dist[u][v] = c;
        dist[v][u] = c;
    }
    floyd();
    ll q;
    cin >> q;// 1Q => o(1)
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

