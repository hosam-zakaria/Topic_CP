// LINK PROBLEM : https://codeforces.com/contest/2085/problem/C

/////////////////////////////////////////////////////////////
// important equation : a + b == a ^ b + (a & b) * 2
// important Notes AND : A && A = A 
///////////////////////////////////////////////////////////////////////


void solve(){
    ll x, y; cin >> x >> y; 
    // (x+k) + (y+k) == (x+k) ^ (y+k)
    // The original equation => a + b == a ^ b + (a & b) * 2
    // the curry +> (a & b) * 2 
    // (a & b) == Zero => a + b == a ^ b
    // when (NO COMMON BITS BETWEEN A , B) => a & b == ZERO 
    // when (Output == -1) => (x == y) => ((x+k) and (y+k)) => ((x+k) and (x+k)) => 
    // Properties of and : A && A == A 
    // x == y => X && X == X (NOT ZERO RESULT) => Output = -1
    // (a & b) == Zero 
    // power of two > Max(a, b) 
    // x , y <= 1e9 => k <= 1e18 +> 1e9 < 2^30 > 1e18 
    // output : (2 ^ 30) 
    // BUT need k : (a + k == zero)
    // OUTPUT : (2 ^ 30 - MAX(x, y)) 

    if (x == y) cout << -1 << endl; 
    else cout << ((1 << 30) - max(x, y)) << endl; 
}
