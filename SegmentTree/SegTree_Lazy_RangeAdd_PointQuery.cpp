#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Node{
    ll val;
    Node(){ val = 0; }
    Node(ll x){ val = x; }
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

    void build(ll node,ll l,ll r,vector<ll> &v){

        if(l==r){
            tree[node]=Node(v[l]);
            return;
        }

        ll mid=(l+r)/2;

        build(node<<1,l,mid,v);
        build(node<<1|1,mid+1,r,v);
    }

    void push(ll node,ll l,ll r){

        if(lazy[node]==0) return;

        tree[node].val+=lazy[node];

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
            lazy[node]+=val;
            push(node,l,r);
            return;
        }

        ll mid=(l+r)/2;

        update(node<<1,l,mid,s,e,val);
        update(node<<1|1,mid+1,r,s,e,val);
    }

    ll query(ll node,ll l,ll r,ll idx){

        push(node,l,r);

        if(l==r)
            return tree[node].val;

        ll mid=(l+r)/2;

        if(idx<=mid)
            return query(node<<1,l,mid,idx);

        return query(node<<1|1,mid+1,r,idx);
    }

};
