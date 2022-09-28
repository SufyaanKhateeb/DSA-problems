#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int fibo(int n, vector<int>& dp) {
    if (n <= 1)
        return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
}

// tabulation basic TC: O(n) SC: O(n)
int fiboBasic(int n) {
    vector<int> dp(n + 1);
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// tabulation TC: O(n) SC: O(1)
int fiboAdvance(int n) {
    int prev = 1, prev2 = 0;
    for (int i = 2; i <= n; i++) {
        int temp = prev;
        prev = prev + prev2;
        prev2 = temp;
    }
    return prev;
}

int main() {
    int n;
    cout << "Enter the nth fibonacci number to get: ";
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << "Fibo of " << n << " is " << fibo(n, dp) << endl;
    cout << "Fibo using basic tabulation of " << n << " is " << fiboBasic(n) << endl;
    cout << "Fibo using advance tabulation of " << n << " is " << fiboAdvance(n) << endl;

    return 0;
}