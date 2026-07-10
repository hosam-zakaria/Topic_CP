// n <= 1e7
ll fact[N];
void calc_fact()
{
    fact[0]=1 ;
    for(int i=1 ; i<N ; i++)
        fact[i]=fact[i-1]*i%MOD ;
}
ll expo_power(ll num, ll p)
{
    ll ans = 1;
    while (p)
    {
        if (p & 1)	ans=(num*ans)%MOD;
        num=num*num%MOD;
        p>>= 1;
    }
    return ans;
}
ll mod_inv(int x) { return expo_power(x,MOD-2)%MOD ; }
ll mod_div(ll a, ll b) { a %= MOD; return (a * mod_inv(b)) % MOD; }
ll nPr(int n ,int r) { return fact[n]*mod_inv(fact[n-r])%MOD; }
ll nCr(int n ,int r) { return fact[n]*mod_inv(fact[r]*fact[n-r]%MOD)%MOD; }
