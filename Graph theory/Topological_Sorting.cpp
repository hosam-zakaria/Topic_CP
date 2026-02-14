#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define Hosam ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const ll oo = 1e9, N = 1e3 + 5, MOD = 1e9 + 7;
const ld PI = acos(-1.0L), EPS = 1e-9;
ll n, m; bool vis[N], rec_stack[N]; 
vector<ll>adj[N]; 
stack<ll> st; 

bool dfs(ll i){
    vis[i] = rec_stack[i] = 1; 
    bool cycle = 0; 
    for(auto &c : adj[i]){
        if(!vis[c]){
            cycle |= dfs(c); 
        }else if(rec_stack[c] == 1){
            return 1; 
            // it is cycle 
        }   
    }
    st.push(i); 
    rec_stack[i] = 0; 
    return cycle; 
}

void solve(){
    cin >> n >> m; 
    for(int i = 1; i <= n; i++){
        adj[i].clear();
        vis[i] = rec_stack[i] = 0;
    }
    while(!st.empty()) st.pop();
    for(ll i = 0; i < m ;i++){
        ll a, b; cin >> a >> b; 
        adj[a].push_back(b); 
        // adj[b].push_back(a); 
    }

    /*
    return dfs => 1 or 0
    1 => it is cycle 
    0 => no cycle 
    */
    if(!dfs(1)){
        while (!st.empty()){
            cout << st.top() << " "; 
            st.pop(); 
        }
    }else {
        cout << "Sandro fails." << endl; 
    }
}

int main(){
    Hosam;
    solve();
    return 0;
}
