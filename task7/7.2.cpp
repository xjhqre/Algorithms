#include <bits/stdc++.h>
using namespace std;

int a[101], dp[101];

int main() {
    int n;
    cin >> n;
    int sum = INT_MIN;  // int类型的最小值
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = max(dp[i - 1] + a[i], a[i]);
        sum = max(sum, dp[i]);
    }
    cout << sum;
    getchar();
    getchar();
    return 0;
}