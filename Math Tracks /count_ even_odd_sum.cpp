// Count & Sum of Even and Odd numbers from 1 to n

ll evenCnt = n / 2;
ll oddCnt  = n - evenCnt;

// Sum of even numbers: 2 + 4 + ... + 2k
// where k = evenCnt
ll evenSum = evenCnt * (evenCnt + 1);

// Sum of odd numbers: 1 + 3 + ... + (2k - 1)
// where k = oddCnt
ll oddSum = oddCnt * oddCnt;
