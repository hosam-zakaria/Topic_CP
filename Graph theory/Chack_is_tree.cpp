// chack find the graph in cycle or Not (undirected graph)

vector<ll> adj[N]; 
bool used[N], flag; 

void DFS(ll node, ll parant){
    used[node] = 1; 
    // cout << node << " "; 
    for(auto c : adj[node]){
        if (!used[c]) { 
            DFS(c, node); 
        }else if (c != parant){
            flag = 1; 
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

    for (ll i = 1; i <= n ;i++) {
        if (!used[i]) {
            DFS(i ,- 1); 
            if(flag){
                cout << "NO" << endl; return; 
            }
        }
    }

    for (ll i = 1; i <= n ;i++) {
        if (!used[i]) { 
            cout << "NO" << endl; return; 
        }
    }
    // DFS(1, -1);  // 1 2 4 5 3 
    cout << "YES" << endl; 
}
