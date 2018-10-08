// mybfs.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <stack>
#include <cstring>
#include <iostream>

#define N 100 //顶点最大数
#define M 1000 //边最大数

using namespace std;

typedef struct node {
	int adjvex;
	node* next;
}EdgeNode;

EdgeNode *node[N]; //node[i]表示顶点i的第一个邻接点地址
int visited[N]; //访问标志

int firstadj(int v); //v第一个邻接点
int nextadj(int v, int w); //v的w之后的邻接点
void bfs(int v);

int main()
{
	//freopen("a.txt","r",stdin);
	int n, m;
	int i;
	EdgeNode *s;
	cin >> n >> m;
	for (i = 1; i < n; i++)
		node[i] = NULL;
	for (i = 0; i < m; i++) { //输入边，邻接矩阵构件图
		int x, y;
		cin >> x >> y;
		s = (EdgeNode*)malloc(sizeof(EdgeNode));
		s->adjvex = y; //插入表头
		s->next = node[x];
		node[x] = s;
		s = (EdgeNode*)malloc(sizeof(EdgeNode)); //无向图
		s->adjvex = x;
		s->next = node[y];
		node[y] = s;
	}

	for (i = 1; i <= n; i++) //打印每个结点及其邻接点
	{
		cout << i << ":";
		int w = firstadj(i);
		while (w != 0) {
			cout << w << " ";
			w = nextadj(i, w);
		}
		cout << endl;
	}

	memset(visited, 0, sizeof(visited));
	cout << "BFS"; bfs(1); //bfs
	cout << endl;

    return 0;
}

int firstadj(int v) {
	if (node[v] != NULL)
		return node[v]->adjvex;
	return 0;
}

int nextadj(int v, int w) {
	EdgeNode *p = node[v];
	while (p != NULL)
	{
		if (p->adjvex == w)
			break;
		p = p->next;
	}
	p = p->next;
	if (p != NULL)
		return p->adjvex;
	return 0;
}

void bfs(int v) {
	int w, u;
	queue<int> q;
	visited[v] = 1;
	cout << v << " ";
	q.push(v);
	while (!q.empty()) {
		w = q.front();
		q.pop();
		u = firstadj(w);
		while (u != 0){
			if (!visited[u]) {
				cout << u << " ";
				visited[u] = 1;
				q.push(u);
			}
			u = nextadj(w, u);
		}
	}
}