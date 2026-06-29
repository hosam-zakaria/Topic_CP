/*
    Reverse Trie for dynamic suffix queries.

    - Insert every string reversed, so suffixes become prefixes.
    - Each node stores cnt = number of active strings passing through it.
    - level[d] is a multiset containing cnt of all nodes at depth d.
    - Maximum frequency at depth d is:
            *level[d].rbegin()

    Operations:
    1) Add string:
        Update cnt along its reversed path.

    2) Remove string:
        Decrease cnt along the same path.

    3) Query(k, l):
        Check if there exists a suffix of length l shared by at least k strings.
        Equivalent to checking:
            max cnt among nodes at depth l >= k

    Complexity:
        Add    : O(|s| log N)
        Remove : O(|s| log N)
        Query  : O(1)
*/

#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define Hosam ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const ll oo = 1e9, N = 1e6, MOD = 1e9 + 7;
const ld PI = acos(-1.0L), EPS = 1e-9;
vector<multiset<ll>> level;
class Trie{
private: 
    struct Node{
        Node* child[26];
        ll cnt, dep;

        Node(ll d = 0){
            memset(child, 0, sizeof(child));
            cnt = 0;
            dep = d;
        }
    };
    Node* root; 
    void clear(Node* nd) {
        if (nd == NULL) return;
        for (int i = 0; i < 26; i++) {
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
        reverse(s.begin(), s.end());
        Node* nd = root; 
        for(auto ch : s){
            if(nd->child[ch - 'a'] == NULL){
                nd->child[ch - 'a'] = new Node(nd->dep + 1);
                if(level.size() <= nd->dep + 1){
                    level.resize(nd->dep + 2);
                }
                level[nd->dep + 1].insert(0);
            }
            nd = nd->child[ch - 'a']; 
            level[nd->dep].erase(level[nd->dep].find(nd->cnt));
            nd->cnt++;
            level[nd->dep].insert(nd->cnt);
        }
    }
    void remove(string s){
        reverse(s.begin(), s.end());
        Node* nd = root;
        for(auto ch : s){
            nd = nd->child[ch - 'a'];
            level[nd->dep].erase(level[nd->dep].find(nd->cnt));
            nd->cnt--;
            level[nd->dep].insert(nd->cnt);
        }
    }

    bool query(ll k, ll l){
        if(level.size() <= l || level[l].empty()) return false;
        return (*level[l].rbegin() >= k);
    }
}; 


ll n; 
void solve(){
    level.clear();
    level.resize(1);
    Trie trie;
    ll q; cin >> q;
    vector<string> add(q + 1);
    vector<bool> remove(q + 1, false);

    for(ll i = 1; i <= q ;i++){
        ll ty; cin >> ty;
        if(ty == 1){
            string s; cin >> s;
            add[i] = s;
            trie.add(s);
        }
        else if(ty == 2){
            ll k, l;
            cin >> k >> l;
            cout << (trie.query(k, l) ? "YES" : "NO") << endl;
        }else{
            ll x; cin >> x;
            if(!remove[x]){
                remove[x] = true;
                trie.remove(add[x]);
            }
        }
    }
}

int main(){
    Hosam;
    solve();
    return 0;
}
