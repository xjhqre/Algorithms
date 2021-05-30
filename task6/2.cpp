#include <bits/stdc++.h>
using namespace std;
#define INF 1e7
#define N 10

int edge[N][N];  //�ڽӾ���洢�����Ȩͼ
int bestp[N];    //���Ž�·��
int bestl;       //���Žⳤ��
int n, m;        //������Ŀ,·����Ŀ

//���нڵ�ṹ��
struct node {
    int cl;       //��ǰ�߹���·������
    int id;       //����ĵڼ�������
    int path[N];  //��¼��ǰ·��
    node(int cl = 0, int id = 0) {
        this->cl = cl;
        this->id = id;
        memset(path, 0, sizeof(path));
    }
    bool operator<(const node &s) const {  //����<��ϵ����>
        return cl > s.cl;
    }
};

//��ʼ�����ڽڵ�
void init() {
    int i, j;
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j)
            edge[i][j] = INF;
    memset(bestp, 0, sizeof(bestp));
    bestl = INF;
}

//�����������
void bfs() {
    priority_queue<node> q;  //�������ȶ���
    node temp(0, 1);         //����Ѿ�ȷ�����ӵڶ������п�ʼ
    int t;
    for (int i = 0; i < n; ++i)
        temp.path[i] = i;
    q.push(temp);
    node live;  //��������
    while (!q.empty()) {
        live = q.top();
        q.pop();
        t = live.id;
        if (t == n - 1) {  //�����������ڶ�������
            if (edge[live.path[t - 1]][live.path[t]] != INF && edge[live.path[t]][0] != INF) {
                if (live.cl + edge[live.path[t - 1]][live.path[t]] + edge[live.path[t]][0] < bestl) {
                    bestl = live.cl + edge[live.path[t - 1]][live.path[t]] + edge[live.path[t]][0];
                    for (int i = 0; i < n; ++i)  //�������Ž�·��Ϊ�����·��
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
    cout << "�����������Ŀ��";
    cin >> n;
    cout << "������·����Ŀ��";
    cin >> m;
    cout << "��������м��·����";
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        if (c < edge[a][b]) {
            edge[a][b] = c;
            edge[b][a] = c;
        }
    }
    bfs();
    cout << "���·������Ϊ��" << bestl << endl;
    cout << "���·��Ϊ��";
    for (int i = 0; i < n; ++i)
        cout << bestp[i] << "-->";
    cout << bestp[0] << endl;
    getchar();
    getchar();
    return 0;
}
