#include<bits/stdc++.h>
#include<queue>
using namespace std;

//��¼��start��end�����·���ṹ��
struct shorTestPath{
	int start;
	int end;
	int value;
	shorTestPath(int start_, int end_, int value_){
		this->start = start_;
		this->end = end_;
		this->value = value_;
	}
};
//�뵱ǰ�ڵ����ڵĽڵ�
struct edge {
	int v, d; //�ڵ� Ȩֵ 
	edge(int v_, int d_){
		this->v = v_;
		this->d = d_;
	}
};
//���ȶ����������·���ṹ�� 
struct priorityQueue {
    int v; //�ڵ�
    int d; //Ȩֵ
    priorityQueue(int v_, int d_){
		this->v = v_;
		this->d = d_;
	}
    bool operator <(const priorityQueue &other) const {
        return d > other.d;	//���ز�����, ���������ȼ����� 
    }
};
int values[50];
bool sign[50];
vector<edge> edges[50];
vector<shorTestPath> stp[50];
int n, m; //n�ǽڵ�����m��·����

void Djikstra(int v)  {
	memset(values, INT_MAX, sizeof(values));
    memset(sign, false, sizeof(sign));
    
    priority_queue<priorityQueue> p; //�������ȶ���q
    p.push(priorityQueue(v, 0));
	 
    while (p.empty() != 1) {
    	priorityQueue temp = p.top();
    	p.pop();
    	if (sign[temp.v]) {	 
    		continue;	//�����ѱ�ǵĽڵ�
		}
		
		sign[temp.v] = true;//��ǽڵ�
		values[temp.v] = temp.d; //����·�� 
		
		//�ɳڲ��� �������·�� 
		vector<edge>::iterator it;
		for (it = edges[temp.v].begin(); it != edges[temp.v].end(); ++it) {
	        p.push(priorityQueue(it->v, temp.d + it->d)); //ѹ�붥����� �Զ����� 
	    }
	}
	
	//���������Դ�ڵ㵽����ÿ���ڵ����С����
    for(int i = 1; i <= n; i++){
    	if (i != v) {
			stp[v].push_back(shorTestPath(v, i, values[i]));
		}
	}     
}

int main()
{
	cout << "����ڵ�����·������" << endl;
    cin >> n >> m;
    int x, v, d, s, e;
    //�����ڽӱ� 
	cout << "�������·����" << endl;
    for(int i=0;i<m;i++)
    {
        cin >> x >> v >> d;
        edges[x].push_back(edge(v, d));
        edges[v].push_back(edge(x, d));
    }
	cout << "��������㣺" << endl;
	cin >> s;
    //ÿ���ڵ㶼����һ��Դ�ڵ� 
	for (int i = 1; i <= n; i++) {
		Djikstra(i);
	}
	cout << "���·����" << endl;
	vector<shorTestPath>::iterator it;
	for (it = stp[s].begin(); it != stp[s].end(); ++it) {
		if (it->start == s){
			cout << it->start << "-->" << it->end << ':' << it->value << endl;
		}
	}
	getchar();
	getchar();
    return 0;
}
