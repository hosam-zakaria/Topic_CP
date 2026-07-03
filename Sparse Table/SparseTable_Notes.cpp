/*
=========================================
Sparse Table - Query Types
=========================================

1) Idempotent Operations
------------------------
If merge(x, x) == x, then the operation is idempotent.

Examples:
- min
- max
- gcd
- bitwise AND
- bitwise OR

Query Complexity: O(1)

Formula:
    int k = __lg(r - l + 1);
    return merge(st[k][l], st[k][r - (1 << k) + 1]);

Reason:
The two intervals may overlap, but duplicate elements do not affect
the result because the operation is idempotent.

------------------------------------------------------------

2) Non-Idempotent Operations
----------------------------
If merge(x, x) != x, overlapping intervals cannot be used.

Examples:
- sum
- xor
- product
- count

Query Complexity: O(log N)

Query by decomposing the interval into disjoint powers of two:

    res = identity;
    len = r - l + 1;

    for (int k = LOG; k >= 0; k--) {
        if ((1 << k) <= len) {
            res = merge(res, st[k][l]);
            l += (1 << k);
            len -= (1 << k);
        }
    }

Reason:
Each element must be counted exactly once.

=========================================
Rule:
- Idempotent  -> O(1) Query (Two Intervals)
- Otherwise   -> O(log N) Query (Power-of-Two Decomposition)
=========================================
*/
