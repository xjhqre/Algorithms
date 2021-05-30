#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<int> arr;
    cout << "输入链表个数：" << endl;
    cin >> n;
    for (int i = 0; i < n; i++){
        int m;
        cout << "输入链表中元素的个数：" << endl;
        cin >> m;
        cout << "输入链表元素："  << endl;
        for (int j = 0; j < m; j++){
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
    }
    sort(arr.begin(), arr.end());
    cout << "排序后链表：" << endl;
    cout << arr[0];
    for(int i = 0; i < arr.size(); i++){
        cout << "->" << arr[i] ;
    }
    getchar();
    getchar();
    return 0;
}