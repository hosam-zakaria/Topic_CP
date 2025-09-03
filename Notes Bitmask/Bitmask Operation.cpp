// Bitmask Operation

ll Knowbit(ll n , ll i){
    return (n >> i) & 1; 
}

ll Setbit(ll n, ll i){
    return n|(1<<i); 
    // change the bit in (n) to (1)
}
ll Resetbit(ll n, ll i){
    return n&~(1<<i); 
    // change the bit in (n) to (0)
}
ll Resetbit2(ll n, ll i){
    return n&(-1 ^ (1<<i)); 
    // change the bit in (n) to (0)
}

ll flip(ll n, ll i){
    return n ^ ((1<<i)); 
    // change the bit in (n) from (0) to (1) OR from (1) to (0)
}

bool isPowerOfTwo(ll n){ // O(1)
    // check the number power of two 
    if (n == 0) return 0; 
    return !(n & (n-1)); 
}

 // check the number power of two 
  if (__builtin_popcountll(n) == 1){
      cout << "is power of two" << endl; 
  }else {
      cout << "not power of two" << endl; 
  }



// All sub Set by bitmask 
void solve(){
    ll n; cin >> n; 
    vector<ll> v(n); 
    for(auto& c : v) { cin >> c; }

    vector<vector<ll>> ans; 

    for(ll masks = 0; masks < (1 << n) ;masks++){

        vector<ll> vv; 
        for(ll i = 0; i < n; ++i) {
            if (Knowbit(masks , i) == 1){
                vv.push_back(v[i]); 
            }
        }

        ans.push_back(vv); 
    }

    sort(ans.begin() , ans.end()); 

    for (auto it : ans){
        for (auto c : it){
            cout << c << " "; 
        }
        cout << "\n"; 
    }
}


