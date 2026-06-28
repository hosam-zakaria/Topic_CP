#include <bits/stdc++.h>
#define ll long long
#define Hosam ios::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

class XOR_Trie {
private:
    static const int BITS = 29; // x < 2^30

    struct Node {
        Node* child[2];
        int cnt;

        Node() {
            child[0] = child[1] = nullptr;
            cnt = 0;
        }
    };

    Node* root;

    void clear(Node* nd) {
        if (!nd) return;
        clear(nd->child[0]);
        clear(nd->child[1]);
        delete nd;
    }

public:
    XOR_Trie() {
        root = new Node();
    }

    ~XOR_Trie() {
        clear(root);
    }

    void add(int x) {
        Node* nd = root;
        nd->cnt++;
        for (int i = BITS; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (!nd->child[bit])
                nd->child[bit] = new Node();
            nd = nd->child[bit];
            nd->cnt++;
        }
    }

    void erase(ll x){
        Node* nd = root;
        nd->cnt--;
        for (ll i = BITS; i >= 0; i--){
            int bit = (x >> i) & 1;
            Node* nxt = nd->child[bit];
            nxt->cnt--;
            if(nxt->cnt == 0){
                clear(nxt);
                nd->child[bit] = nullptr;
                return;
            }
            nd = nxt;
        }
    }

    int minXor(int x) {
        Node* nd = root;
        int ans = 0;
        for (int i = BITS; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (nd->child[bit]) {
                nd = nd->child[bit];
            } else {
                ans |= (1 << i);
                nd = nd->child[bit ^ 1];
            }
        }
        return ans;
    }
    int maxXor(int x){
        Node* nd = root;
        int ans = 0;

        for(int i = BITS; i >= 0; i--){
            int bit = (x >> i) & 1;

            if(nd->child[bit ^ 1]){
                ans |= (1 << i);
                nd = nd->child[bit ^ 1];
            }
            else{
                nd = nd->child[bit];
            }
        }

        return ans;
    }
};

int main(){
    Hosam
    ll q;
    cin >> q;
    XOR_Trie trie;
    unordered_set<ll> st;
    while(q--){
        ll t, x;
        cin >> t >> x;
        if(t == 0){ 
            if(!st.count(x)){
                st.insert(x);
                trie.add(x);
            }
        }
        else if(t == 1){ 
            if(st.count(x)){
                st.erase(x);
                trie.erase(x);
            }
        }
        else{ 
            cout << trie.minXor(x) << '\n';
        }
    }

    return 0;
}
