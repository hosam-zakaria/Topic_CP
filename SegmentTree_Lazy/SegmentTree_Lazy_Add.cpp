#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node{
    ll sum;

    Node(){
        sum = 0;
    }

    Node(ll val){
        sum = val;
    }
};

struct LazySeg{

    vector<Node> tree;
    vector<ll> lazy;

    LazySeg(ll n){
        tree.resize(n << 2);
        lazy.assign(n << 2,0);
    }

    LazySeg(ll n,vector<ll> &v){
        tree.resize(n << 2);
        lazy.assign(n << 2,0);
        build(1,0,n-1,v);
    }

    // Merge
    Node merge(Node left,Node right){
        Node ret;
        ret.sum = left.sum + right.sum;
        return ret;
    }

    // Build
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

    // Push Lazy
    // O(1)
    void push(ll node,ll l,ll r){

        if(!lazy[node]) return;

        tree[node].sum += (r-l+1)*lazy[node];

        if(l!=r){
            lazy[node<<1]+=lazy[node];
            lazy[node<<1|1]+=lazy[node];
        }

        lazy[node]=0;
    }

    // Range Add
    // add x to [s,e]
    // O(log n)
    void update(ll node,ll l,ll r,ll s,ll e,ll x){

        push(node,l,r);

        if(l>e || r<s)
            return;

        if(l>=s && r<=e){

            lazy[node]+=x;
            push(node,l,r);

            return;
        }

        ll mid=(l+r)>>1;

        update(node<<1,l,mid,s,e,x);
        update(node<<1|1,mid+1,r,s,e,x);

        tree[node]=merge(tree[node<<1],tree[node<<1|1]);
    }

    // Range Sum Query
    // O(log n)
    Node query(ll node,ll l,ll r,ll s,ll e){

        push(node,l,r);

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
};
