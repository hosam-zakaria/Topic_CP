vector<ll> adj[N + 1];
bool used[N + 1];
void DFS(ll node){
    used[node] = 1;
    cout << node << " ";
    for(auto c : adj[node]){
        if (!used[c]) {
            DFS(c);
        }
    }
}

void solve(){
    /*
    input Graph:
    n = 5 path = 4
    1 2
    2 4
    2 5
    1 3
    */
    ll n, x; cin >> n >> x;
    for(ll i = 0; i < x ;i++){
        ll a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DFS(1);  // 1 2 4 5 3
    cout << endl;
    cout << (used[4] && used[5] && used[3] ? "YES" : "NO") << endl;
}
