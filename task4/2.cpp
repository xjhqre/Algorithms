#include<bits/stdc++.h>
#define MAXN 100
using namespace std;
 
int parent[MAXN], Rank[MAXN];
//两个节点与边结构体
struct Path
{
    int a;
    int b;
    int value;
}path[MAXN];
//sort排序规则
int cmp(Path a, Path b){
    return a.value < b.value;
}

void Init(int n){
    for(int i = 1; i <= n; i++){
        Rank[i] = 1;
        parent[i] = i;
    }
}
//寻找根节点
int find(int x){
    int root = x;
    while(root != parent[root]) root = parent[root];
    while(x != root){
        int t = parent[x];
        parent[x] = root;
        x = t;
    }
    return root;
}
//合并两个树
void Union(int x, int y){
    x = find(x);
    y = find(y);
    if(Rank[x] < Rank[y]){
        parent[x] = y;
    }
    else{
        parent[y] = x;
        if(Rank[x] == Rank[y]) Rank[x]++;
    }
}
//n为边的数量，m为节点的数量
int Kruskal(int n, int m){
    int result = 0; //权值最小和
    //将边按照权值从小到大排序
    sort(path+1, path+n+1, cmp);
    for(int i = 1; i <= n; i++){
        //判断当前这条边的两个节点是否属于同一棵树
        if(find(path[i].a) != find(path[i].b)){
            Union(path[i].a, path[i].b);
            result += path[i].value;
        }
    }
    return result;
}
int main(){
    //定义边数n,结点数m
    int n, m;
    while(cin >> n >> m){
        Init(m);
        for(int i = 1; i <= n; i++){
            cin >> path[i].a >> path[i].b >> path[i].value;
        }
        cout << Kruskal(n, m) << endl << endl;
    }
    return 0;
}