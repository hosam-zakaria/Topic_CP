// sieve => chack number prime or not O(n log log n)
void sieve() {
    fill(prime, prime + mx + 1, true);
    prime[0] = prime[1] = false; // 0 1 Not Prime 
    for (ll i = 2; i * i <= mx; ++i) {
        if (prime[i]){ 
            for (ll j = i*i; j <= mx; j += i) {
                prime[j] = false;  
            }
        }
    }
}
