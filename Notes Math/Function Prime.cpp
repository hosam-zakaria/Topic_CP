 // time complexity >> O(N)
bool prime(ll n) {
    if(n == 1 || n == 0) return false; 
    for(ll i = 2; i < n ;i++){
        if(n % 2 == 0) {
            return false; 
        }
    }
    return true; 
}

// time complexity >> O(sqrt(n))
 bool prime(ll n) { 
    if(n == 1 || n == 0) return false; 
    for(ll i = 2; i * i <= n ;i++){
        if(n % 2 == 0) {
            return false; 
        }
    }
    return true; 
}
