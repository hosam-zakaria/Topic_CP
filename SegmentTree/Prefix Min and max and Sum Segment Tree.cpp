#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define Hosam ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const ll oo = 1e9, N = 1e6, MOD = 1e9 + 7;
const ld PI = acos(-1.0L), EPS = 1e-9;
struct Node{
    ll sum, mn;
    Node(){
        sum = 0;
        mn = 0;
    }
    Node(ll val){
        sum = val;
        mn = min(0LL, val);
        mx = max(0LL, val);
    }
};
struct segtree{
    vector<Node> tree;

    segtree(ll n){
        tree.resize(n << 2);
    }

    segtree(ll n, vector<ll> &v){
        tree.resize(n << 2);
        build(1, 0, n - 1, v);
    }

    Node merge(Node left, Node right){
        Node ret;
        ret.sum = left.sum + right.sum;
        ret.mn = min(left.mn, left.sum + right.mn);
        ret.mx = max(left.mx, left.sum + right.mx);
        return ret;
    }

    void build(ll node, ll l, ll r, vector<ll> &v){
        if(l == r){
            tree[node] = Node(v[l]);
            return;
        }

        ll mid = (l + r) >> 1;
        build(node << 1, l, mid, v);
        build(node << 1 | 1, mid + 1, r, v);

        tree[node] = merge(tree[node << 1], tree[node << 1 | 1]);
    }

    void update(ll node, ll l, ll r, ll idx, ll val){
        if(l == r){
            tree[node] = Node(val);
            return;
        }
        ll mid = (l + r) >> 1;
        if(idx <= mid)
            update(node << 1, l, mid, idx, val);
        else
            update(node << 1 | 1, mid + 1, r, idx, val);

        tree[node] = merge(tree[node << 1], tree[node << 1 | 1]);
    }

    Node query(ll node, ll l, ll r, ll s, ll e){
        if(l > e || r < s)
            return Node(0);

        if(l >= s && r <= e)
            return tree[node];

        ll mid = (l + r) >> 1;

        return merge(
            query(node << 1, l, mid, s, e),
            query(node << 1 | 1, mid + 1, r, s, e)
        );
    }
};
void solve(){
    ll n, sum = 0, cnt = 0; cin >> n;
    vector<ll> v(n * 2), tree(n * 2, 1);
    vector<pair<ll, ll>> pr(n * 2);
    for(ll i = 0; i < n * 2; i++){
        cin >> v[i];
        sum += v[i];
        pr[i] = {v[i], i};
    }
    sort(pr.begin(), pr.end());
    segtree seg(n * 2, tree);
    for(ll i = 0; i < n * 2 ;i++){
        ll val = pr[i].first, idx = pr[i].second;
        if(cnt == n){
            break;
        }
        seg.update(1, 0, (n * 2) - 1, idx, -1);        
        if(seg.tree[1].mn >= 0){
            sum -= val;
            cnt++;
        }else{
            seg.update(1, 0, (n * 2) - 1, idx, 1);
        }
    }
    
    cout << sum << endl;
}

int main(){
    Hosam;
    ll t; cin >> t;
    while(t--) { solve(); } 
    return 0;
}
