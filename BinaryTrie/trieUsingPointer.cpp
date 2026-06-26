#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define Hosam ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const ll oo = 1e9, N = 1e6, MOD = 1e9 + 7;
const ld PI = acos(-1.0L), EPS = 1e-9;


class Trie{
private:
    struct Node{
        bool isLeaf = 1; 
        bool isEnd = 0; 
        vector<Node*>child = vector<Node*>(26, NULL); 
    }; 
    Node* root; 
public: 
    Trie(){
        root = new Node();
    }
    void add(string s){
        Node* nd = root; 
        for(auto ch : s){
            if(nd->child[ch - 'a'] == NULL){
                nd->isLeaf = 0; 
                nd->child[ch - 'a'] = new Node; 
            }
            nd = nd->child[ch - 'a']; 
        }
        nd->isEnd = 1; 
    }

    bool find_string(string s){
        Node* nd = root; 
        for(auto ch : s){
            if(nd->child[ch - 'a'] == NULL) return 0; 
            nd = nd->child[ch - 'a']; 
        }
        return nd->isEnd; 
    }

    bool isPrefix(string s){
        Node* nd = root; 
        for(auto ch : s){
            nd = nd->child[ch - 'a']; 
        }
        return nd->isLeaf; 
    }

}; 

void solve(){
    ll t; cin >> t; 
    while(t--){
        ll n; 
        cin >> n; 
        vector<string>arr(n); 
        Trie trie = Trie(); 
        for(auto &c : arr) { cin >> c; trie.add(c); }
        ll ans = 1; 
        for(auto s : arr){
            if(trie.isPrefix(s)){
                ans = 0; 
            }
        }
        if(ans == 1){ cout << "YES" << endl; }
        else {cout << "NO" << endl; }
    }
}

int main(){
    Hosam;
    solve();
    return 0;
}
