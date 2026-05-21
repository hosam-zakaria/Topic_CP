#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define Hosam ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const ll oo = 1e9, N = 1e6, MOD = 1e9 + 7;
const ld PI = acos(-1.0L), EPS = 1e-9;


struct Node {
    vector<ll> nxt; ll cnt; 
    Node() : nxt(26, -1), cnt(0) {} 
};

struct Trie {
    vector<Node> trie; 
    ll sz; 

    Trie() {sz = 0, addNode(); }
    ll addNode(){
        trie.emplace_back(); 
        return sz++; 
    }

    void insert(string &s){
        ll cur = 0; 
        for(auto &c : s){
            if(trie[cur].nxt[c - 'a'] == -1){
                trie[cur].nxt[c - 'a'] = addNode();
            }
            cur = trie[cur].nxt[c - 'a']; 
            trie[cur].cnt++; 
        }
    }

    ll query(string &s){
        ll cur = 0; 
        for(auto &c : s){
            if(trie[cur].nxt[c - 'a'] == -1) return 0; 
            cur = trie[cur].nxt[c - 'a'];
        }

        return trie[cur].cnt; 
    }
};


void solve(){
    Trie trie; 

    ll n, q; 
    cin >> n >> q; 
    for(ll i = 0; i < n ;i++){
        string s; cin >> s; 
        trie.insert(s);
    }

    for(ll i = 0; i < q ;i++){
        string s; cin >> s; 
        cout << trie.query(s) << endl; 
    }
}

int main(){
    Hosam;
    solve();
    return 0;
}
