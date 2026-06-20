// ============================================
// PBDS (Policy Based Data Structure) Template
// ============================================

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

// Ordered Set
template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

/*
============================================
Basic Operations
============================================

ordered_set<int> st;

Insert:
st.insert(x);          // O(log n)

Erase:
st.erase(x);           // O(log n)

Search:
st.find(x);            // O(log n)

Count:
st.count(x);           // O(log n)

Size:
st.size();             // O(1)

============================================
Order Statistics
============================================

1) find_by_order(k)
Returns iterator to kth element (0-based)

Example:
st = {10,20,30,40}

*st.find_by_order(0) => 10
*st.find_by_order(2) => 30

Complexity: O(log n)

--------------------------------------------

2) order_of_key(x)
Returns count of elements strictly less than x

Example:
st = {10,20,30,40}

st.order_of_key(30) => 2

Complexity: O(log n)

============================================
Useful Queries
============================================

// First element >= x
auto it = st.lower_bound(x);

// First element > x
auto it = st.upper_bound(x);

// Largest element < x
auto it = st.lower_bound(x);
if(it != st.begin()){
    --it;
    cout << *it;
}

============================================
Multiset PBDS
============================================

ordered_set<pair<int,int>> st;

st.insert({value, unique_id});

Example:
st.insert({5,1});
st.insert({5,2});
st.insert({5,3});

============================================
Complexities
============================================

insert           O(log n)
erase            O(log n)
find             O(log n)
find_by_order    O(log n)
order_of_key     O(log n)

============================================
Common Uses
============================================

1. Josephus Problem II
2. K-th Smallest Element
3. Dynamic Rankings
4. Inversion Count
5. Count numbers < x
6. Order Statistics Queries

============================================
Most Important Functions
============================================

st.find_by_order(k); // kth element (0-based)

st.order_of_key(x);  // count of elements < x

*/
