#include<bits/stdc++.h>
using namespace std;

vector<int> result; //�洢����
void backtracking(int n, int k, int startindex){
    if (result.size() == k){ // ��������
        for(int i = 0; i < result.size(); i++){
            cout << result[i] << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = startindex; i <= n; i++){
        result.push_back(i); //����������
        backtracking(n, k, i+1);
        result.pop_back(); //�������¼������
    }
}

int main() {
    int n, k;
    cout << "���룺" << endl;
    cin >> n >> k;
    cout << "�����" << endl;
    backtracking(n, k, 1);
    getchar();
    getchar();
    return 0;
}