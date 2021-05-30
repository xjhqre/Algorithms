#include<bits/stdc++.h>
using namespace std;

bool func(vector<string> s, int startindex){
    for (int i = 0; i < s.size()-1; i++){
        if (s[i][startindex] != s[i+1][startindex]){
            return false;
        }
    }
    return true;
}

int main() {
    int n, maxlen = 0;
    cin >> n;
    vector<string> s;
    for (int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        if (temp.size() > maxlen) maxlen = temp.size();
        s.push_back(temp);
    }
    string result;
    for (int i = 0; i < maxlen; i++){
        if (func(s, i)) result = result + s[0][i];
        else break;
    }
    cout << result;
    return 0;
}