// postOrder.cpp : 定义控制台应用程序的入口点。
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

	//后序递归遍历
	void postOrder1(BinTree *root)
	{
		if (root != NULL)
		{
			postOrder1(root->lchild);
			postOrder1(root->rchild);
			cout << root->data << " ";
		}
	}

	//非递归后序遍历
	//第一种思路：对于任一结点P，将其入栈，然后沿其左子树一直往下搜索，
	//直到搜索到没有左孩子的结点，此时该结点出现在栈顶，但是此时不能将
	//其出栈并访问，因此其右孩子还为被访问。所以接下来按照相同的规则对
	//其右子树进行相同的处理，当访问完其右孩子时，该结点又出现在栈顶，
	//此时可以将其出栈并访问。这样就保证了正确的访问顺序。可以看出，在
	//这个过程中，每个结点都两次出现在栈顶，只有在第二次出现在栈顶时，
	//才能访问它。因此需要多设置一个变量标识该结点是否是第一次出现在栈顶。
	
	void postOrder2(BinTree *root)
	{
		stack<BTNode*> s;
		BinTree *p = root;
		BTNode *temp;
		while (p != NULL || !s.empty())
		{
			//沿左子树一直往下搜索，直至出现没有左子树的结点
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
				if (temp->isFirst == true) //表示第一次出现在栈顶
				{
					temp->isFirst = false;
					s.push(temp);
					p = temp->btnode->rchild;
				}
				else //第二次出现
				{
					cout << temp->btnode->data << " ";
					p = NULL;
				}
			}
		}
	}

	//第二种思路：要保证根结点在左孩子和右孩子访问之后才能访问，
	//因此对于任一结点P，先将其入栈。如果P不存在左孩子和右孩子，
	//则可以直接访问它；或者P存在左孩子或者右孩子，但是其左孩子
	//和右孩子都已被访问过了，则同样可以直接访问该结点。若非上述
	//两种情况，则将P的右孩子和左孩子依次入栈，这样就保证了每次取
	//栈顶元素的时候，左孩子在右孩子前面被访问，左孩子和右孩子都
	//在根结点前面被访问。
	void postOrder3(BinTree *root)
	{
		stack<BinTree*> s;
		BinTree *cur;           //当前结点
		BinTree *pre = NULL;    //第一次访问的结点
		if (!root) return;
		s.push(root);
		while (!s.empty())
		{
			cur = s.top();
			//如果当前结点没有孩子结点或者孩子节点都访问过
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




