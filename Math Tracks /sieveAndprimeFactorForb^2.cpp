// SPF + Number of divisors of x² + Prefix of (div(x²)-1)/2
/*
    Smallest Prime Factor (SPF)

    val[x]  = number of divisors of x²
            = Π (2 * exponent + 1)

    pref[x] = Σ((val[i] - 1) / 2), 1 <= i <= x
*/
vector<ll> spf(N + 1), val(N + 1), pref(N + 1);

void sieve(){
    for(ll i = 0; i <= N; i++) { spf[i] = i; } 
    for(ll i = 2; i * i <= N ;i++){
        if(spf[i] == i){
            for(ll j = i * i; j <= N; j += i){
                if(spf[j] == j){spf[j] = i;}
            }
        }
    }
    val[1] = 1;
    pref[1] = 0;
    for(ll x = 2; x <= N; x++){
        ll y = x, ans = 1;
        while(y > 1){
            ll p = spf[y], cnt = 0;
            while(y % p == 0){
                y /= p;
                cnt++;
            }
            ans *= (2 * cnt + 1);
        }
        val[x] = ans;
        pref[x] = pref[x - 1] + (val[x] - 1) / 2;
    }
}
