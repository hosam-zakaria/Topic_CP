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
        vector<Node*>child = vector<Node*>(10, NULL); 
    }; 
    Node* root; 
    void clear(Node* nd) {
        if (nd == NULL) return;
        for (int i = 0; i < 10; i++) {
            if (nd->child[i] != NULL) {
                clear(nd->child[i]);
            }
        }
        delete nd;
    }
public: 
    Trie(){
        root = new Node();
    }
    ~Trie() {
        clear(root);
    }
    void add(string s){
        Node* nd = root; 
        for(auto ch : s){
            if(nd->child[ch - '0'] == NULL){
                nd->isLeaf = 0; 
                nd->child[ch - '0'] = new Node; 
            }
            nd = nd->child[ch - '0']; 
        }
        nd->isEnd = 1; 
    }

    bool find_string(string s){
        Node* nd = root; 
        for(auto ch : s){
            if(nd->child[ch - '0'] == NULL) return 0; 
            nd = nd->child[ch - '0']; 
        }
        return (nd->isLeaf == 0);
    }

    bool isPrefix(string s){
        Node* nd = root; 
        for(auto ch : s){
            nd = nd->child[ch - '0']; 
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
            if(trie.isPrefix(s) == 0){
                ans = 0; 
                break;
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
