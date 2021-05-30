#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt = 0; //统计逆序数对数

void Merge(int arr[], int left, int middle, int right){
    int temp[right-left+1]; // 将要排序的数组放入temp数组
    for (int i = left; i <= right; i++){
        temp[i - left] = arr[i];
    }
    int i = left, j = middle+1;
    for (int k = left; k <= right; k++){
        if (i > middle && j <= right){ //例如21， 34 数组排序，21排成12后i>middle
            arr[k] = temp[j-left];
            j++;
        }
        else if (j > right && i <= middle){ //例如43， 21 数组排序，21排成12后j>right
            arr[k] = temp[i-left];
            i++;
        }
        else if (temp[i-left] > temp[j-left]){
            arr[k] = temp[j-left];
            cnt += middle - i + 1; //例如数组[3,4]和数组[1,2]合并，3和1先进行比较，3比1大，就是一个逆序数，又因为4比3大，所以也是一个逆序数，所以cnt+=2。
            j++;
        }
        else if (temp[i-left] <= temp[j-left]){
            arr[k] = temp[i-left];
            i++;
        }
    }
}

void Mergesort(int arr[], int left, int right){
    if (left >= right) return;
    int middle = (left + right)/2;
    Mergesort(arr, left, middle);
    Mergesort(arr, middle + 1, right);
    Merge(arr, left, middle, right);
}

int main() {
    int n;
    cout << "输入数组大小：";
    cin >> n;
    int a[n] = {0};
    cout << "输入数组：";
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    Mergesort(a, 0, n-1);
    cout << "逆序数对数：" << cnt << endl;
    getchar();
    getchar();
    return 0;
}