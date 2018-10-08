// postOrder.cpp : �������̨Ӧ�ó������ڵ㡣
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
	bool isFirst;
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
	void postOrder1(BinTree *root)
	{
		if (root != NULL)
		{
			postOrder1(root->lchild);
			postOrder1(root->rchild);
			cout << root->data << " ";
		}
	}

	//�ǵݹ�������
	//��һ��˼·��������һ���P��������ջ��Ȼ������������һֱ����������
	//ֱ��������û�����ӵĽ�㣬��ʱ�ý�������ջ�������Ǵ�ʱ���ܽ�
	//���ջ�����ʣ�������Һ��ӻ�Ϊ�����ʡ����Խ�����������ͬ�Ĺ����
	//��������������ͬ�Ĵ��������������Һ���ʱ���ý���ֳ�����ջ����
	//��ʱ���Խ����ջ�����ʡ������ͱ�֤����ȷ�ķ���˳�򡣿��Կ�������
	//��������У�ÿ����㶼���γ�����ջ����ֻ���ڵڶ��γ�����ջ��ʱ��
	//���ܷ������������Ҫ������һ��������ʶ�ý���Ƿ��ǵ�һ�γ�����ջ����
	
	void postOrder2(BinTree *root)
	{
		stack<BTNode*> s;
		BinTree *p = root;
		BTNode *temp;
		while (p != NULL || !s.empty())
		{
			//��������һֱ����������ֱ������û���������Ľ��
			while (p != NULL)
			{
				BTNode *btn = (BTNode*)malloc(sizeof(BTNode));
				btn->btnode = p;
				btn->isFirst = true;
				s.push(btn);
				p = p->lchild;
			}
			if (!s.empty())
			{
				temp = s.top();
				s.pop();
				if (temp->isFirst == true) //��ʾ��һ�γ�����ջ��
				{
					temp->isFirst = false;
					s.push(temp);
					p = temp->btnode->rchild;
				}
				else //�ڶ��γ���
				{
					cout << temp->btnode->data << " ";
					p = NULL;
				}
			}
		}
	}

	//�ڶ���˼·��Ҫ��֤����������Ӻ��Һ��ӷ���֮����ܷ��ʣ�
	//��˶�����һ���P���Ƚ�����ջ�����P���������Ӻ��Һ��ӣ�
	//�����ֱ�ӷ�����������P�������ӻ����Һ��ӣ�����������
	//���Һ��Ӷ��ѱ����ʹ��ˣ���ͬ������ֱ�ӷ��ʸý�㡣��������
	//�����������P���Һ��Ӻ�����������ջ�������ͱ�֤��ÿ��ȡ
	//ջ��Ԫ�ص�ʱ���������Һ���ǰ�汻���ʣ����Ӻ��Һ��Ӷ�
	//�ڸ����ǰ�汻���ʡ�
	void postOrder3(BinTree *root)
	{
		stack<BinTree*> s;
		BinTree *cur;           //��ǰ���
		BinTree *pre = NULL;    //��һ�η��ʵĽ��
		if (!root) return;
		s.push(root);
		while (!s.empty())
		{
			cur = s.top();
			//�����ǰ���û�к��ӽ����ߺ��ӽڵ㶼���ʹ�
			if ((cur->lchild==NULL&&cur->rchild==NULL)
				|| (pre != NULL && (pre == cur->lchild || pre == cur->rchild)))
			{
				cout << cur->data << " ";
				s.pop();
				pre = cur;
			}
			else
			{
				if (cur->rchild != NULL)
					s.push(cur->rchild);
				if (cur->lchild != NULL)
					s.push(cur->lchild);
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
		s.postOrder2(root);
		cout << endl;
	}

	system("pause");

	return 0;
}




