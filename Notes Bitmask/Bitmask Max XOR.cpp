
// Max XOR between the Range L and R 
ll x = l ^ r;

while (x > 0) {
    k++;
    x >>= 1; 
}

ll ans = (1LL << k) - 1;


 // check power of 2
if((x & (x - 1)) == 0)
    

// proof Min Xor of the equation 
// Min( (a ^ x) + (x ^ b) ) = (a ^ b) 


/*
lowest set bit in (x) => (x & -x)

-x is represented in two's complement:
  1. Invert all bits of x
  2. Add 1

Example: x = 12
Binary:  x  = 1100
          ~x = 0011
       ~x+1 = 0100   => this is -12

Now:
  x  = 1100
 -x  = 0100
x&-x = 0100 = 4  --> lowest set bit of x
*/
