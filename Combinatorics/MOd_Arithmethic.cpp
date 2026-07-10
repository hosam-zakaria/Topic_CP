// MOd Arithmethic 
( a + b ) % c =  ((a % c) + (b % c)) % c 
( a * b ) % c =  ((a % c) * (b % c)) % c 
( a - b ) % c =  ((a % c) - (b % c) + c) % c 
( a / b ) % c =  ((a % c) * (b^-1 % c)) % c 

inline ll add(ll a, ll b) {a%=mod;b%=mod;ll x=a+b; return x>=mod ? x-mod:x;}

inline ll mul(ll a, ll b) {a%=mod;b%=mod;ll x=a*b; return x>=mod ? x%mod:x;}

ll sub(ll a, ll b) { return ((a % mod) - (b % mod) + mod) % mod; }

ll mod_inv(int x) { return fast_power(x,MOD-2)%MOD ; }

ll mod_div(ll a, ll b) { a %= MOD; return (a * mod_inv(b)) % MOD; }
