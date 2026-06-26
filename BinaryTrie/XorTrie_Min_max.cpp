#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define Hosam ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const ll oo = 1e9, N = 1e6, MOD = 1e9 + 7;
const ld PI = acos(-1.0L), EPS = 1e-9;

class XOR_Trie{
private:
    static const int BITS = 62;
    struct Node{
        Node* child[2] = {nullptr, nullptr};
    };

    Node* root;
    void clear(Node* nd){
        if(!nd) return;
        clear(nd->child[0]);
        clear(nd->child[1]);
        delete nd;
    }
public:
    XOR_Trie(){
    root = new Node();
    }
    ~XOR_Trie(){
        clear(root);
    }
    void add(ll x){
        Node* nd = root;
        for(int i = BITS ; i >= 0 ; i--){
            int bit = (x >> i) & 1;
            if(nd->child[bit] == nullptr){
                nd->child[bit] = new Node();
            }
            nd = nd->child[bit];
        }
    }

    ll maxXor(ll x){
        Node* nd = root;
        ll ans = 0;
        for(int i = BITS ; i >= 0 ; i--){
            int bit = (x >> i) & 1;
            if(nd->child[bit ^ 1]){
                ans |= (1LL << i);
                nd = nd->child[bit ^ 1];
            }
            else{
                nd = nd->child[bit];
            }
        }
        return ans;
    }

    ll minXor(ll x){
        Node* nd = root;
        ll ans = 0;
        for(int i = BITS ; i >= 0 ; i--){
            int bit = (x >> i) & 1;
            if(nd->child[bit]){
                nd = nd->child[bit];
            }
            else{
                ans |= (1LL << i);
                nd = nd->child[bit ^ 1];
            }
        }
        return ans;
    }
};

void solve(){
    XOR_Trie trie = XOR_Trie(); 
    ll n, m; 
    cin >> n >> m; 
    while(n--){
        ll x; 
        cin >> x; 
        trie.add(x); 
    }

    while(m--){
        ll x; 
        cin >> x; 
        cout << trie.maxXor(x) << endl;
        cout << trie.minXor(x) << endl;
    }
}

int main(){
    Hosam;
    solve();
    return 0;
}
