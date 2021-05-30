#include <bits/stdc++.h>
using namespace std;

int numWays(int n) {
    int *dp = new int[n + 1];
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i < n + 1; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    }
    return dp[n];
}

int main() {
    int n;
    while (cin >> n) {
        cout << numWays(n) << endl;
    }
    getchar();
    getchar();
    return 0;
}