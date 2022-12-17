/*A. Sequence with Digits
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Let's define the following recurrence:
an+1=an+minDigit(an)⋅maxDigit(an).
Here minDigit(x) and maxDigit(x) are the minimal and maximal digits in the decimal 
representation of x without leading zeroes. For examples refer to notes.

Your task is calculate aK for given a1 and K.

Input
The first line contains one integer t (1≤t≤1000) — the number of independent test cases.

Each test case consists of a single line containing two integers a1 and K (1≤a1≤10^18, 
1≤K≤10^16) separated by a space.

Output
For each test case print one integer aK on a separate line.*/