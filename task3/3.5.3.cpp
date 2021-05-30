#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n] = {0};
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    if (arr[0] != 0) cout << 0;//判断0缺失的情况
    else{
        int left = 0, right = n-1;
        while (left < right){
            int mid = left + (right - left + 1)/2;
            if (arr[mid] >= mid + arr[0] + 1){
                right = mid - 1;
            }
            else left = mid;
        }
        cout << arr[0] + left + 1; //left即缺失元素前一个元素的下标
    }
    getchar();
    getchar();
    return 0;
}