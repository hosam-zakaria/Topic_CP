#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node{
    ll sum, mx;

    Node(){
        sum = 0;
        mx = 0;
    }

    Node(ll val){
        sum = mx = val;
    }
};

struct segtree{

    vector<Node> tree;

    segtree(ll n){
        tree.resize(n << 2);
    }

    segtree(ll n, vector<ll> &v){
        tree.resize(n << 2);
        build(1,0,n-1,v);
    }

    //================ Merge ==================
    Node merge(Node left, Node right){
        Node ret;
        ret.sum = left.sum + right.sum;
        ret.mx = max(left.mx,right.mx);
        return ret;
    }

    //================ Build ==================
    // O(n)
    void build(ll node,ll l,ll r,vector<ll> &v){

        if(l==r){
            tree[node]=Node(v[l]);
            return;
        }

        ll mid=(l+r)>>1;

        build(node<<1,l,mid,v);
        build(node<<1|1,mid+1,r,v);

        tree[node]=merge(tree[node<<1],tree[node<<1|1]);
    }

    //================ Query ==================
    // Range Query O(log n)
    Node query(ll node,ll l,ll r,ll s,ll e){

        if(l>e || r<s)
            return Node(0);

        if(l>=s && r<=e)
            return tree[node];

        ll mid=(l+r)>>1;

        return merge(
            query(node<<1,l,mid,s,e),
            query(node<<1|1,mid+1,r,s,e)
        );
    }

    //================ Point Set ==================
    // a[pos]=val
    // O(log n)
    void update_set(ll node,ll l,ll r,ll pos,ll val){

        if(l==r){
            tree[node]=Node(val);
            return;
        }

        ll mid=(l+r)>>1;

        if(pos<=mid)
            update_set(node<<1,l,mid,pos,val);
        else
            update_set(node<<1|1,mid+1,r,pos,val);

        tree[node]=merge(tree[node<<1],tree[node<<1|1]);
    }

    //================ Point Add ==================
    // a[pos]+=val
    // O(log n)
    void update_add(ll node,ll l,ll r,ll pos,ll val){

        if(l==r){
            tree[node].sum+=val;
            tree[node].mx+=val;
            return;
        }

        ll mid=(l+r)>>1;

        if(pos<=mid)
            update_add(node<<1,l,mid,pos,val);
        else
            update_add(node<<1|1,mid+1,r,pos,val);

        tree[node]=merge(tree[node<<1],tree[node<<1|1]);
    }

    //================ Point Max ==================
    // a[pos]=max(a[pos],x)
    // O(log n)
    void update_max(ll node,ll l,ll r,ll pos,ll x){

        if(l==r){
            tree[node].sum=max(tree[node].sum,x);
            tree[node].mx=tree[node].sum;
            return;
        }

        ll mid=(l+r)>>1;

        if(pos<=mid)
            update_max(node<<1,l,mid,pos,x);
        else
            update_max(node<<1|1,mid+1,r,pos,x);

        tree[node]=merge(tree[node<<1],tree[node<<1|1]);
    }

    //================ Point Min ==================
    // a[pos]=min(a[pos],x)
    // O(log n)
    void update_min(ll node,ll l,ll r,ll pos,ll x){

        if(l==r){
            tree[node].sum=min(tree[node].sum,x);
            tree[node].mx=tree[node].sum;
            return;
        }

        ll mid=(l+r)>>1;

        if(pos<=mid)
            update_min(node<<1,l,mid,pos,x);
        else
            update_min(node<<1|1,mid+1,r,pos,x);

        tree[node]=merge(tree[node<<1],tree[node<<1|1]);
    }

    //================ Range Mod ==================
    // a[i]%=x
    // O(log² n) تقريبًا
    void update_mod(ll node,ll l,ll r,ll s,ll e,ll x){

        if(l>e || r<s || tree[node].mx<x)
            return;

        if(l==r){
            tree[node].sum%=x;
            tree[node].mx%=x;
            return;
        }

        ll mid=(l+r)>>1;

        update_mod(node<<1,l,mid,s,e,x);
        update_mod(node<<1|1,mid+1,r,s,e,x);

        tree[node]=merge(tree[node<<1],tree[node<<1|1]);
    }

    //================ First >= x ==================
    // أول Index قيمته >= x
    // O(log n)
    ll first_greater(ll node,ll l,ll r,ll x){

        if(tree[node].mx<x)
            return -1;

        if(l==r)
            return l;

        ll mid=(l+r)>>1;

        if(tree[node<<1].mx>=x)
            return first_greater(node<<1,l,mid,x);

        return first_greater(node<<1|1,mid+1,r,x);
    }

    //================ Prefix Lower Bound ==================
    // أول Prefix Sum >= x
    // O(log n)
    ll lower_bound(ll node,ll l,ll r,ll x){

        if(l==r)
            return l;

        ll mid=(l+r)>>1;

        if(tree[node<<1].sum>=x)
            return lower_bound(node<<1,l,mid,x);

        return lower_bound(
            node<<1|1,
            mid+1,
            r,
            x-tree[node<<1].sum
        );
    }

    //================ K-th One ==================
    // tree.sum = frequency
    // O(log n)
    ll kth(ll node,ll l,ll r,ll k){

        if(l==r)
            return l;

        ll mid=(l+r)>>1;

        if(tree[node<<1].sum>=k)
            return kth(node<<1,l,mid,k);

        return kth(
            node<<1|1,
            mid+1,
            r,
            k-tree[node<<1].sum
        );
    }

};
