
// Max XOR between the Range L and R 
ll x = l ^ r;

while (x > 0) {
    k++;
    x >>= 1; 
}

ll ans = (1LL << k) - 1;



// proof Min Xor of the equation 
// Min( (a ^ x) + (x ^ b) ) = (a ^ b) 
