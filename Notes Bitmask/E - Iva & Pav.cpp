////////////////////////////////////////
// E - Iva & Pav
// Link problem : https://codeforces.com/contest/1878/problem/E
////////////////////////////////////////
int n, q;
// int v[n], prefix[32][n]; 
vector<int> v;
vector<vector<int>> prefix;
int get_and(int l, int r){
    int ans = 0;
    for(int i = 0; i < 31; i++){
        int cnt = prefix[i][r];
        if(l > 0) cnt -= prefix[i][l-1];
        if(cnt == (r - l + 1))
            ans |= (1 << i);
    }
    return ans;
}


void solve(){
    cin >> n; 
    v.resize(n);
    prefix.assign(32, vector<int>(n));
    for(auto &c : v) { cin >> c; }

    for(int i = 0; i <= 31 ;i++){ // i = Bit 
        for(int j = 0; j < n ;j++){ // 
            prefix[i][j] = ((v[j] >> i) & 1); // return 1 or 0 
            // (num & (1 << Bit) => return (2 ^ bit) Or 0
            if (j > 0) prefix[i][j] += prefix[i][j - 1]; 
        }
    }
    int l , k, ans;
    cin >> q; 
    while (q--){
        cin >> l >> k; l--;   ans = 0; 

        int lo = l, hi = n-1, res = -1;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            int val = get_and(l, mid);
            if(val >= k){
                res = mid;
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
        cout << (res == -1 ? -1 : res + 1) << " ";
    }
    cout << endl; 
}

int main(){
    Hosam;
    ll t; cin >> t;
    while(t--){ solve(); }
    return 0;
}
