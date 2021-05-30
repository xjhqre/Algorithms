#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &tree, int n, int i){
    if (i >= n) return;
    int c1 = 2 * i + 1;
    int c2 = 2 * i + 2;
    int minn = i;
    if (c1 < n && tree[c1] < tree[minn]){
        minn = c1;
    }
    if (c2 < n && tree[c2] < tree[minn]){
        minn = c2;
    }
    if (minn != i){
        swap(tree[minn], tree[i]);
    }
}

void build_heap(vector<int> &tree, int n){
    int last_node = n - 1;
    int parent_node = (last_node - 1) / 2;
    for (int i = parent_node; i >= 0; i--){
        heapify(tree, n, i);
    }
}

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
    vector<int> result;
    for (int i = arr.size(); i > 0; i--){
        build_heap(arr, i);
        result.push_back(arr[0]);
        arr.erase(arr.begin(), arr.begin()+1);
    }
    cout << "排序后链表：" << endl;
    cout << result[0];
    for(int i = 0; i < result.size(); i++){
        cout << "->" << result[i] ;
    }
    getchar();
    getchar();
    return 0;
}