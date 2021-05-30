#include<bits/stdc++.h>
using namespace std;

int QuickSort(int arr[], int l, int h){
    int i = l, j = h;
    int temp;
    if(i < j){
        temp = arr[i]; //选取数组第一个元素为基准
        while (i != j)
        {
            while(j > i && arr[j] > temp) j--;
            arr[i] = arr[j];
            while(i < j && arr[i] < temp) i++;
            arr[j] = arr[i];
        }
        arr[i] = temp;
        return i;
    }
}

int main() {
    int n;
    cout << "输入数组的大小：" << endl;
    cin >> n;
    int arr[n] = {0};
    cout << "输入数组：" << endl;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int index = QuickSort(arr, 0, 5);
    cout << "划分一次后支点数在数组中的索引：" << endl;
    cout << index;
    getchar();
    getchar();
    return 0;
}