// midOrder.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cctype>
#include <stdio.h>

#pragma warning(disable:4996)

using namespace std;

typedef struct node
{
	char data;
	struct node *lchild, *rchild;
}BinTree;

typedef struct node1 {
	BinTree *btnode;
	bool isfirst;
}BTNode;


class Solution {
public:
	//创建二叉树，s为形如A（B，C（D,E））形式的字符串
	void creatBinTree(char *s, BinTree *&root)
	{
		int i;
		bool isRight = false;
		stack<BinTree*> s1; //存放节点
		stack<char> s2; //存放分隔符
		BinTree *p, *temp;
		root->data = s[0];
		root->lchild = NULL;
		root->rchild = NULL;
		s1.push(root);
		i = 1;
		while (i < strlen(s))
		{
			if (s[i] == '(')
			{
				s2.push(s[i]);
				isRight = false;
			}
			else if (s[i] == ',')
			{
				isRight = true;
			}
			else if (s[i] == ')')
			{
				s1.pop();
				s2.pop();
			}
			else if (isalpha(s[i]))
			{
				p = (BinTree *)malloc(sizeof(BinTree));
				p->data = s[i];
				p->lchild = NULL;
				p->rchild = NULL;
				temp = s1.top();
				if (isRight == true)
				{
					temp->rchild = p;
					cout << temp->data << "的右孩子是" << s[i] << endl;
				}
				else
				{
					temp->lchild = p;
					cout << temp->data << "的左孩子是" << s[i] << endl;
				}
				if (s[i + 1] == '(')
					s1.push(p);
			}
			i++;
		}
	}

	void display(BinTree *root) //显示树形结构
	{
		if (root != NULL)
		{
			cout << root->data;
			if (root->lchild != NULL)
			{
				cout << "(";
				display(root->lchild);
			}
			if (root->rchild != NULL)
			{
				cout << ",";
				display(root->rchild);
				cout << ")";
			}
		}
	}

	//中序递归遍历
	void midOrder1(BinTree *root)
	{
		if (root != NULL)
		{
			midOrder1(root->lchild);
			cout << root->data << " ";
			midOrder1(root->rchild);
		}
	}

	//非递归中序遍历
	void midOrder2(BinTree *root)
	{
		stack<BinTree*> s;
		BinTree *p = root;
		while (p != NULL || !s.empty())
		{
			while (p != NULL)
			{
				s.push(p);
				p = p->lchild;
			}
			if (!s.empty())
			{
				p = s.top();
				cout << p->data << " ";
				s.pop();
				p = p->rchild;
			}
		}
	}


	char str[100];
};

int main()
{
	Solution s;
	while (scanf("%s", s.str) == 1)
	{
		BinTree *root = (BinTree *)malloc(sizeof(BinTree));
		s.creatBinTree(s.str, root);
		s.display(root);
		cout << endl;
		s.midOrder2(root);
		cout << endl;
	}

	system("pause");

	return 0;
}


