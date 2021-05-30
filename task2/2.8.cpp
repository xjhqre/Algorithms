#include<bits/stdc++.h>
using namespace std;

vector<int> result; //存储数组
void backtracking(int n, int k, int startindex){
    if (result.size() == k){ // 结束条件
        for(int i = 0; i < result.size(); i++){
            cout << result[i] << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = startindex; i <= n; i++){
        result.push_back(i); //加入新数据
        backtracking(n, k, i+1);
        result.pop_back(); //弹出最新加入的数
    }
}

int main() {
    int n, k;
    cout << "输入：" << endl;
    cin >> n >> k;
    cout << "输出：" << endl;
    backtracking(n, k, 1);
    getchar();
    getchar();
    return 0;
}