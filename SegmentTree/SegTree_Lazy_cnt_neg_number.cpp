#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define Hosam ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const ll oo = 1e9, N = 1e6, MOD = 1e9 + 7;
const ld PI = acos(-1.0L), EPS = 1e-9;

struct Node{
    ll mx, mn, neg;
    Node(){ 
        mx = -oo; 
        mn = oo; 
        neg = 0; 
    }
    Node(ll x){ 
        mx = mn = x; 
        neg = (x < 0 ? 1 : 0); 
    }
};

struct segtree{

    vector<Node> tree;
    vector<ll> lazy;

    segtree(ll n){
        tree.resize(4*n);
        lazy.assign(4*n,0);
    }

    segtree(ll n, vector<ll> &v){
        tree.resize(4*n);
        lazy.assign(4*n,0);
        build(1,0,n-1,v);
    }
    Node merge(Node &left, Node &right) {
        Node x;
        x.mx = max(left.mx, right.mx);
        x.mn = min(left.mn, right.mn);
        x.neg = left.neg + right.neg;
        return x;
    }

    void build(ll node,ll l,ll r,vector<ll> &v){

        if(l==r){
            tree[node]=Node(v[l]);
            return;
        }

        ll mid=(l+r)/2;

        build(node<<1,l,mid,v);
        build(node<<1|1,mid+1,r,v);
        tree[node] = merge(tree[node<<1], tree[node<<1|1]);
    }

    void push(ll node,ll l,ll r){

        if(lazy[node]==0) return;

        tree[node].mx += lazy[node];
        tree[node].mn += lazy[node];
        if(tree[node].mx < 0){
            tree[node].neg = (r - l + 1);
        }else if(tree[node].mn >= 0){
            tree[node].neg = 0;
        }
        if(l!=r){
            lazy[node<<1]+=lazy[node];
            lazy[node<<1|1]+=lazy[node];
        }

        lazy[node]=0;
    }

    void update(ll node,ll l,ll r,ll s,ll e,ll val){

        push(node,l,r);

        if(r<s || l>e) return;
        if(s<=l && r<=e){
            if (l == r || (tree[node].mx + val < 0) || (tree[node].mn + val >= 0)) {
                lazy[node] += val;
                push(node,l,r);
                return;
            }
        }
        ll mid=(l+r)/2;
        update(node<<1,l,mid,s,e,val);
        update(node<<1|1,mid+1,r,s,e,val);
        
        push(node<<1, l, mid);
        push(node<<1|1, mid+1, r);
        tree[node] = merge(tree[node<<1], tree[node<<1|1]);
    }

    ll query(ll node, ll l, ll r, ll s, ll e){
        push(node,l,r);
        if(r<s || l>e) return 0;
        if(s<=l && r<=e) return tree[node].neg;
        ll mid=(l+r)/2;
        return query(node<<1,l,mid,s,e) + query(node<<1|1,mid+1,r,s,e);
    }

};
void solve(){
    ll n, q; cin >> n >> q; 
    vector<ll> v(n); 
    for(ll i = 0; i < n ;i++){
        cin >> v[i]; 
    }  
    /*
    - (4)
    -3 1 -5 3 6
    -7 -3 -9 -1 2
    */

    segtree sg(n, v); 
    while(q--){
        ll ty; cin >> ty;
        if(ty == 1){ 
            ll l, r, val; 
            cin >> l >> r >> val;
            sg.update(1, 0, n - 1, l, r, -val); 
        }else{ 
            ll l, r; 
            cin >> l >> r;
            cout << sg.query(1, 0, n - 1, l, r) << endl; 
        }
    }
}

int main(){
    Hosam;
    ll t; cin >> t;
    while(t--){ solve(); }
    return 0;
}
