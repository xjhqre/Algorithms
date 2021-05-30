#include <bits/stdc++.h>
using namespace std;

int longestSubstring(string x, string y) {
    string res;
    for (int i = 0; i < x.size(); i++) {
        if (y.find(x[i]) == y.npos)
            continue;
        string temp;
        int index = 0;
        for (int j = i; j < x.size(); j++) {
            if (y.find(x[j], index) == y.npos) {
                continue;
            }
            temp += x[j];
            index = y.find(x[j]) + 1;
        }
        if (res.size() < temp.size()) {
            res = temp;
        }
    }
    return res.size();
}

int main() {
    string x, y;
    while (cin >> x) {
        cin >> y;
        cout << longestSubstring(x, y) << endl;
    }
    getchar();
    getchar();
    return 0;
}