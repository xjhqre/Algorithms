#include <bits/stdc++.h>
using namespace std;
#define INF 1e7
#define N 10

int edge[N][N];  //邻接矩阵存储无向带权图
int bestp[N];    //最优解路径
int bestl;       //最优解长度
int n, m;        //城市数目,路径数目

//城市节点结构体
struct node {
    int cl;       //当前走过的路径长度
    int id;       //处理的第几个城市
    int path[N];  //记录当前路径
    node(int cl = 0, int id = 0) {
        this->cl = cl;
        this->id = id;
        memset(path, 0, sizeof(path));
    }
    bool operator<(const node &s) const {  //重载<关系函数>
        return cl > s.cl;
    }
};

//初始化相邻节点
void init() {
    int i, j;
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j)
            edge[i][j] = INF;
    memset(bestp, 0, sizeof(bestp));
    bestl = INF;
}

//广度优先搜索
void bfs() {
    priority_queue<node> q;  //创建优先队列
    node temp(0, 1);         //起点已经确定，从第二个城市开始
    int t;
    for (int i = 0; i < n; ++i)
        temp.path[i] = i;
    q.push(temp);
    node live;  //创建活结点
    while (!q.empty()) {
        live = q.top();
        q.pop();
        t = live.id;
        if (t == n - 1) {  //当处理到倒数第二个城市
            if (edge[live.path[t - 1]][live.path[t]] != INF && edge[live.path[t]][0] != INF) {
                if (live.cl + edge[live.path[t - 1]][live.path[t]] + edge[live.path[t]][0] < bestl) {
                    bestl = live.cl + edge[live.path[t - 1]][live.path[t]] + edge[live.path[t]][0];
                    for (int i = 0; i < n; ++i)  //更改最优解路径为活结点的路径
                        bestp[i] = live.path[i];
                }
            }
            continue;
        }
        if (live.cl >= bestl)
            continue;
        for (int j = t; j < n; ++j) {
            if (edge[live.path[t - 1]][live.path[j]] != INF && live.cl + edge[live.path[t - 1]][live.path[j]] < bestl) {
                temp = node(live.cl + edge[live.path[t - 1]][live.path[j]], t + 1);
                for (int k = 0; k < n; ++k)
                    temp.path[k] = live.path[k];
                swap(temp.path[t], temp.path[j]);
                q.push(temp);
            }
        }
    }
}

int main() {
    init();
    cout << "请输入城市数目：";
    cin >> n;
    cout << "请输入路径数目：";
    cin >> m;
    cout << "请输入城市间的路径：";
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        if (c < edge[a][b]) {
            edge[a][b] = c;
            edge[b][a] = c;
        }
    }
    bfs();
    cout << "最短路径长度为：" << bestl << endl;
    cout << "最短路径为：";
    for (int i = 0; i < n; ++i)
        cout << bestp[i] << "-->";
    cout << bestp[0] << endl;
    getchar();
    getchar();
    return 0;
}
