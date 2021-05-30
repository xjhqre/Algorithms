#include <bits/stdc++.h>
using namespace std;
#define MAXN 10

int n;                  //人员和任务数量
int c[MAXN][MAXN];      //人员任务表
int best[MAXN];         //最优分配方案
int mincost = INT_MAX;  //最小成本
int cnt = 1;            //计算节点个数

//队列结点类型
struct Node {
    int n_n;                               //结点编号
    int p_n;                               //人数统计
    int t_n[MAXN];                         //人员i分配的任务编号
    bool sign[MAXN];                       //标记被分配的任务
    int cost;                              //当前已分配任务的总成本
    int l_b;                               //下界
    bool operator<(const Node &s) const {  //重载<关系函数>
        return l_b > s.l_b;
    }
};

void bound(Node &e) {  //求结点e的界限值
    int sum = 0;
    for (int i = e.p_n + 1; i <= n; i++) {  //查找每行中的最小元素
        int temp = INT_MAX;
        for (int j = 1; j <= n; j++) {
            if (e.sign[j] == false && c[i][j] < temp)
                temp = c[i][j];
        }
        sum += temp;
    }
    e.l_b = e.cost + sum;
}

void bfs() {
    int j;
    Node first;
    priority_queue<Node> qu;
    memset(first.t_n, 0, sizeof(first.t_n));    //初始化根节点的任务分配
    memset(first.sign, 0, sizeof(first.sign));  //初始化根节点的任务标记
    first.p_n = 0;                              //标记根节点的人员编号为0，即不选人分配任务
    first.cost = 0;
    bound(first);       //求根节点的下限
    first.n_n = cnt++;  //设置根节点编号为1
    qu.push(first);     //根节点进队列
    while (!qu.empty()) {
        Node cur = qu.top();
        qu.pop();            //弹出队列结点
        if (cur.p_n == n) {  //当cur中的p_n等于n时，即已选则n个人处理n个任务
            mincost =
                cur.cost;  // cur中的cost即为最小代价，不再考虑别的分支的节点
            for (j = 1; j <= n; j++) {
                best[j] = cur.t_n[j];
            }
            break;
        }
        Node live;
        live.p_n = cur.p_n + 1;     //从cur节点展开到子节点，人员数+1
        for (j = 1; j <= n; j++) {  //考虑n个任务
            if (cur.sign[j])        //任务j是否标记
                continue;
            for (int i = 1; i <= n; i++) {  //设置任务分配与父节点相同
                live.t_n[i] = cur.t_n[i];
            }
            live.t_n[live.p_n] = j;         // live.pn分配任务j
            for (int k = 1; k <= n; k++) {  //设置任务标记与父节点相同
                live.sign[k] = cur.sign[k];
            }
            live.sign[j] = true;                    //标记新任务j
            live.cost = cur.cost + c[live.p_n][j];  //计算当前节点的cost
            bound(live);                            //求当前节点的下限
            live.n_n = cnt++;                       //标记当前节点序号
            qu.push(live);                          //把节点放入优先序列
        }
    }
}
int main() {
    cout << "输入人员数/任务数的大小：n" << endl;
    cin >> n;
    cout << "输入人员-任务成本值" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    bfs();
    printf("最优方案：\n");
    for (int k = 1; k <= n; k++)
        printf("第%d个人员分配第%d个任务\n", k, best[k]);
    cout << "总成本=" << mincost;
    getchar();
    getchar();
    return 0;
}
