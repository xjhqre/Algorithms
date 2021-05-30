#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y = 1;
    cin >> x >> n;
    for (int i = 0; i < n; i++){
        y *= x;
    }
    cout << y;
    return 0;
}