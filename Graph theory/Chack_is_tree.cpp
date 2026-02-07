// chack find the graph in cycle or Not (undirected graph)

vector<ll> adj[N + 1]; 
ll used[N + 1], flag = false; 

void DFS(ll node, ll parant){
    used[node]++; 
    // cout << node << " "; 
    for(auto c : adj[node]){
        if (!used[c]) { 
            DFS(c, node); 
        }else if (c != parant){
            cout << "cycle" << endl; 
            return; 
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
    DFS(1, -1);  // 1 2 4 5 3 
    cout << "YES Tree" << endl; 
}
