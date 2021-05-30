#include<bits/stdc++.h>
using namespace std;

int fun(int x, int y){
    int temp = 0;
    if (y == 1){
        return x;
    }
    else if (y % 2 == 0){
        temp = fun(x, y/2);
        return temp * temp;
    }
    else if (y % 2 == 1){
        temp = fun(x, (y-1)/2);
        return temp*temp*x;
    }
}

int main() {
    int x, y, ans;
    cin >> x >> y;
    ans = fun(x, y);
    cout << ans;
    return 0;
}