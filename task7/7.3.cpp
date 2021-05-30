#include <bits/stdc++.h>
using namespace std;

int a[101], dp[101];

int main() {
    int n, res = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        dp[i] = 1;  // 初始化dp[i]=1
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(dp[i], res);
    }
    cout << res;
    getchar();
    getchar();
    return 0;
}