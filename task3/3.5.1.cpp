#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n+1] = {0};
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int i = 0;
    while (1){
        if (arr[i] != i){
            cout << i;
            break;
        }
        i++;
    }
    getchar();
    getchar();
    return 0;
}