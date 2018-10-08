// mydfs.cpp : 定义控制台应用程序的入口点。
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
	cout << "DFS:";	dfs(1);  //dfs
	cout << endl;
	memset(visited, 0, sizeof(visited));
	cout << "DFS:";	nonRecursivedfs(1);  //dfs
	cout << endl;

	system("pause");
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

void dfs(int v) {
	int w;
	visited[v] = 1;
	cout << v << " ";
	w = firstadj(v);
	while (w != 0)
	{
		if (!visited[w])
			dfs(w);
		w = nextadj(v, w);
	}
}

void nonRecursivedfs(int v) //dfs非递归写法
{
	int temp, w;
	stack<int> s;
	visited[v] = 1;
	cout << v << " ";
	s.push(v);
	while (!s.empty()) {
		temp = s.top(); //temp指向栈顶元素
		w = firstadj(temp); //栈顶元素为第一邻接点
		if (!visited[w]) {
			cout << w << " ";
			visited[w] = 1;
			s.push(w);
		}
		else { //否则，访问下一个没有被访问的邻接点并入栈
			w = nextadj(temp, w);
			while (w != 0) {
				if (!visited[w]) {
					cout << w << " ";
					visited[w] = 1;
					s.push(w);
					break;
				}
				else
					w = nextadj(temp, w);
			}
			if (w == 0) //所有邻接点都被访问则出栈
				s.pop();
		}
	}
}