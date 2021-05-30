#include<bits/stdc++.h>
using namespace std;

vector<string> res;      // 存放所有排列结果
string path;            // 存放单个排列结果

// 回溯算法
void backTracking(string ss, vector<bool> &used){
    // 如果path的长度等于输入字符串的长度则退出
    if (path.size() == ss.size()){
        res.push_back(path);    //把一个结果放入res
        return;
    }
    for (int i = 0; i < ss.size(); i++){
        if (used[i] == true) continue;    // 检查是否用过此字符
        used[i] = true;                  // 如果没用过则标记为使用
        path.push_back(ss[i]);
        backTracking(ss, used);        // 进行递归
        path.pop_back();              // 回溯，弹出最新加入的字符
        used[i] = false;             //把刚弹出的字符重新标记为未使用
    }
}

// 打印全排列
void printstring(vector<string> res){
    cout << endl;
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }
}

int main() {
    string ss;
    cin >> ss;
    vector<bool> used(ss.size(), false);     //创建标记数组并初始化为false
    backTracking(ss, used);
    printstring(res);
    getchar();
    getchar();
    return 0;
}