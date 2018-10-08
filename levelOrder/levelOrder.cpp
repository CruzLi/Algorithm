// levelOrder.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cctype>
#include <stdio.h>
#include <stack>

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
	//������������sΪ����A��B��C��D,E������ʽ���ַ���
	void creatBinTree(char *s, BinTree *&root)
	{
		int i;
		bool isRight = false;
		stack<BinTree*> s1; //��Žڵ�
		stack<char> s2; //��ŷָ���
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
					cout << temp->data << "���Һ�����" << s[i] << endl;
				}
				else
				{
					temp->lchild = p;
					cout << temp->data << "��������" << s[i] << endl;
				}
				if (s[i + 1] == '(')
					s1.push(p);
			}
			i++;
		}
	}

	void display(BinTree *root) //��ʾ���νṹ
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

	//����ݹ����
	void levelOrder1(BinTree *root)
	{
		queue<BinTree*> rootLevel;
		rootLevel.push(root);
		levelOrder1(rootLevel);
	}

	void levelOrder1(queue<BinTree*> curLevel)
	{
		if (curLevel.empty()) return;
		queue<BinTree*> nextLevel;
		BinTree* temp;
		while (!curLevel.empty())
		{
			temp = curLevel.front();
			curLevel.pop();
			cout << temp->data << " ";

			if (temp->lchild != NULL)
				nextLevel.push(temp->lchild);
			if (temp->rchild != NULL)
				nextLevel.push(temp->rchild);
		}
		levelOrder1(nextLevel);
	}

	//�ǵݹ�����������
	void levelOrder2(BinTree *root)
	{
		queue<BinTree*> q;
		BinTree *temp;
		if (root)
		{
			q.push(root);
			while (!q.empty())
			{
				temp = q.front();
				q.pop();
				cout << temp->data << " ";
				if (temp->lchild != NULL) q.push(temp->lchild);
				if (temp->rchild != NULL) q.push(temp->rchild);
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
		s.levelOrder2(root);
		cout << endl;
	}

	system("pause");

	return 0;
}




