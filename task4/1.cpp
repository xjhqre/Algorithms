#include<bits/stdc++.h>
#include<queue>
using namespace std;

//记录从start到end的最短路径结构体
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
//与当前节点相邻的节点
struct edge {
	int v, d; //节点 权值 
	edge(int v_, int d_){
		this->v = v_;
		this->d = d_;
	}
};
//优先队列生成最短路径结构体 
struct priorityQueue {
    int v; //节点
    int d; //权值
    priorityQueue(int v_, int d_){
		this->v = v_;
		this->d = d_;
	}
    bool operator <(const priorityQueue &other) const {
        return d > other.d;	//重载操作符, 距离大的优先级靠后 
    }
};
int values[50];
bool sign[50];
vector<edge> edges[50];
vector<shorTestPath> stp[50];
int n, m; //n是节点数，m是路径数

void Djikstra(int v)  {
	memset(values, INT_MAX, sizeof(values));
    memset(sign, false, sizeof(sign));
    
    priority_queue<priorityQueue> p; //创建优先队列q
    p.push(priorityQueue(v, 0));
	 
    while (p.empty() != 1) {
    	priorityQueue temp = p.top();
    	p.pop();
    	if (sign[temp.v]) {	 
    		continue;	//跳过已标记的节点
		}
		
		sign[temp.v] = true;//标记节点
		values[temp.v] = temp.d; //保存路径 
		
		//松弛操作 更新最短路径 
		vector<edge>::iterator it;
		for (it = edges[temp.v].begin(); it != edges[temp.v].end(); ++it) {
	        p.push(priorityQueue(it->v, temp.d + it->d)); //压入顶点距离 自动排序 
	    }
	}
	
	//最终输出从源节点到其他每个节点的最小距离
    for(int i = 1; i <= n; i++){
    	if (i != v) {
			stp[v].push_back(shorTestPath(v, i, values[i]));
		}
	}     
}

int main()
{
	cout << "输入节点数和路径数：" << endl;
    cin >> n >> m;
    int x, v, d, s, e;
    //建立邻接表 
	cout << "输入具体路径：" << endl;
    for(int i=0;i<m;i++)
    {
        cin >> x >> v >> d;
        edges[x].push_back(edge(v, d));
        edges[v].push_back(edge(x, d));
    }
	cout << "输入出发点：" << endl;
	cin >> s;
    //每个节点都当做一次源节点 
	for (int i = 1; i <= n; i++) {
		Djikstra(i);
	}
	cout << "最短路径：" << endl;
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
