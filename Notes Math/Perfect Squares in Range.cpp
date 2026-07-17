/*
    Counting Perfect Squares in a Range [L, R]

    Number of perfect squares <= X = floor(sqrt(X))

    Therefore:

        perfect_squares(L, R)
        = floor(sqrt(R)) - floor(sqrt(L - 1))

    In this problem:

        L = c * p + l
        R = c * p + r

    So:

        ans += floorl(sqrtl(c * p + r))
             - floorl(sqrtl(c * p + l - 1));

    Example:
        L = 183184
        R = 183999

        floor(sqrt(183999)) = 428
        floor(sqrt(183183)) = 427

        Answer = 428 - 427 = 1

    Time Complexity:
        O(1) for each range.
*/
