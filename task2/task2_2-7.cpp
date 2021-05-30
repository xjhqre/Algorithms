#include<bits/stdc++.h>
using namespace std;

int a[100][100]; //开一个二维数组

int fun(int i, int j, int n){
    if (i == n) return a[n][j]; //递归结束条件
    else{
        return fun(i+1, j, n) + fun(i+1, j+1, n); //递归
    }
}

int main() {
    int n; //输入数组的个数
    cin >> n;
    for (int i = 1; i <=n; i++){
        cin >> a[n][i]; //输入数组A
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            printf("%-4d ", fun(i, j, n));
        }
        printf("\n");
    }

    return 0;
}