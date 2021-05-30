#include <bits/stdc++.h>
using namespace std;
#define MAXN 10

int n;                  //��Ա����������
int c[MAXN][MAXN];      //��Ա�����
int best[MAXN];         //���ŷ��䷽��
int mincost = INT_MAX;  //��С�ɱ�
int cnt = 1;            //����ڵ����

//���н������
struct Node {
    int n_n;                               //�����
    int p_n;                               //����ͳ��
    int t_n[MAXN];                         //��Աi�����������
    bool sign[MAXN];                       //��Ǳ����������
    int cost;                              //��ǰ�ѷ���������ܳɱ�
    int l_b;                               //�½�
    bool operator<(const Node &s) const {  //����<��ϵ����>
        return l_b > s.l_b;
    }
};

void bound(Node &e) {  //����e�Ľ���ֵ
    int sum = 0;
    for (int i = e.p_n + 1; i <= n; i++) {  //����ÿ���е���СԪ��
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
    memset(first.t_n, 0, sizeof(first.t_n));    //��ʼ�����ڵ���������
    memset(first.sign, 0, sizeof(first.sign));  //��ʼ�����ڵ��������
    first.p_n = 0;                              //��Ǹ��ڵ����Ա���Ϊ0������ѡ�˷�������
    first.cost = 0;
    bound(first);       //����ڵ������
    first.n_n = cnt++;  //���ø��ڵ���Ϊ1
    qu.push(first);     //���ڵ������
    while (!qu.empty()) {
        Node cur = qu.top();
        qu.pop();            //�������н��
        if (cur.p_n == n) {  //��cur�е�p_n����nʱ������ѡ��n���˴���n������
            mincost =
                cur.cost;  // cur�е�cost��Ϊ��С���ۣ����ٿ��Ǳ�ķ�֧�Ľڵ�
            for (j = 1; j <= n; j++) {
                best[j] = cur.t_n[j];
            }
            break;
        }
        Node live;
        live.p_n = cur.p_n + 1;     //��cur�ڵ�չ�����ӽڵ㣬��Ա��+1
        for (j = 1; j <= n; j++) {  //����n������
            if (cur.sign[j])        //����j�Ƿ���
                continue;
            for (int i = 1; i <= n; i++) {  //������������븸�ڵ���ͬ
                live.t_n[i] = cur.t_n[i];
            }
            live.t_n[live.p_n] = j;         // live.pn��������j
            for (int k = 1; k <= n; k++) {  //�����������븸�ڵ���ͬ
                live.sign[k] = cur.sign[k];
            }
            live.sign[j] = true;                    //���������j
            live.cost = cur.cost + c[live.p_n][j];  //���㵱ǰ�ڵ��cost
            bound(live);                            //��ǰ�ڵ������
            live.n_n = cnt++;                       //��ǵ�ǰ�ڵ����
            qu.push(live);                          //�ѽڵ������������
        }
    }
}
int main() {
    cout << "������Ա��/�������Ĵ�С��n" << endl;
    cin >> n;
    cout << "������Ա-����ɱ�ֵ" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    bfs();
    printf("���ŷ�����\n");
    for (int k = 1; k <= n; k++)
        printf("��%d����Ա�����%d������\n", k, best[k]);
    cout << "�ܳɱ�=" << mincost;
    getchar();
    getchar();
    return 0;
}
