#include<bits/stdc++.h>
using namespace std;

int f(string x){
    if(x.size() == 1) return x[0]-'0';
    return (x[x.size()-1]-'0') + f(x.substr(0, x.size()-1))*10;
}

int main() {
    string n;
    cin >> n;
    cout << f(n);
    return 0;
}