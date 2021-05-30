#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int a[], int k){
    if (k == 0) return;
    for (int i = 0; i < k-1; i++){
        if (a[i] > a[i+1]){
            int temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
        }
    }
    bubbleSort(a, k-1);
}

int main() {
    int n;
    cin >> n;
    int a[n] = {0};
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    bubbleSort(a, n);
    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
    return 0;
}