void solve(){
    int n, q; cin >> n; 
    int v[n], prefix[32][n]; 
    for(auto &c : v) { cin >> c; }

    for(int i = 0; i <= 31 ;i++){ // i = Bit 
        for(int j = 0; j < n ;j++){ // 
            prefix[i][j] = ((v[j] >> i) & 1); // return 1 or 0 
            // (num & (1 << Bit) => return (2 ^ bit) Or 0
            if (j > 0) prefix[i][j] += prefix[i][j - 1]; 
        }
    }
    int l , r, ans;
    cin >> q; 
    while (q--){
        cin >> l >> r; l--; r--;  ans = 0; 

        for(int i = 0; i <= 31 ;i++) {
            int cntBit = prefix[i][r]; 
            if (l > 0) cntBit -= prefix[i][l - 1]; 

            // Set Bit => OR 
            if (cntBit == (r - l + 1)) ans |= (1 << i); 
        }
        cout << ans << endl; 
    }
}

int main(){
    Hosam;
    ll t; cin >> t;
    while(t--){ solve(); }
    return 0;
}
