// heapSort.cpp : 定义控制台应用程序的入口点。
//

// fastSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
#define M 10

using namespace std;

class Solution {
public:
	void heapSort(vector<int> &a)
	{
		int N = a.size();
		for (int k = (N - 1) / 2; k >= 0; k--)
			sink(a, k, N);
				
		
		/*while (N > 0)
		{
			swap(a[0], a[N - 1]); N--;
			sink(a, 0, N);
		}
		*/

		//改进，先下沉再上浮
		while (N > 0)
		{
			int temp = a[N - 1];
			a[N - 1] = a[0]; a[0] = 0; N--; //把最大元素放在数组末尾，堆序列长度减1。
			int k = 0; //根节点 
			int j = 2 * k + 1;//左子节点
			while (j <= N - 1)
			{
				if (j < N - 1 && a[j] < a[j + 1]) j++; 
				a[k] = a[j]; //用子节点中较大的结点替代根节点
				k = j; j = 2 * k + 1;
			}

			a[k] = temp; //把堆尾元素放入空缺节点
			swim(a, k); 
		}
	}

	void sink(vector<int> &a, int k, int N)
	{
		int j = 2 * k + 1;
		while (j <= N - 1)
		{
			if (j < N - 1 && a[j] < a[j + 1]) j++;
			if (a[k] >= a[j]) break;
			swap(a[k], a[j]);
			k = j;
		}
	}

	void swim(vector<int> &a, int k)
	{
		//因为根节点不是从零开始，所以父节点索引存在两种可能
		while (k > 0)
		{
			if (k % 2)
			{
				if (a[k / 2] < a[k]) swap(a[k / 2], a[k]); 
				k = k / 2;
			}
			else
			{
				if (a[k / 2 - 1] < a[k]) swap(a[k / 2 - 1], a[k]); 
				k = k / 2 - 1;
			}	
		}
	}

	void insert(vector<int> &a, int lo, int hi)
	{
		int i, j, min;
		for (i = lo; i <= hi; i++)
		{
			min = a[i];
			for (j = i; j > lo && min < a[j - 1]; j--) a[j] = a[j - 1];
			a[j] = min;
		}
	}
};

int main()
{
	double time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	int N = 100;
	//vector<int> vec{ 3, 7, 1, 5, 9, 2, 6, 4, 8, 15 };
	vector<int> vec;
	for (int i = 0; i < N; i++)
	{
		vec.push_back(i + 1);
	}
	random_shuffle(vec.begin(), vec.end());

	cout << "origiral data:" << endl;
	for (auto c : vec)
	{
		cout << c << " ";
	}
	cout << endl;

	Solution s;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时  

	s.heapSort(vec);

	QueryPerformanceCounter(&nEndTime);//停止计时  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  

	cout << "final data:" << endl;
	for (auto c : vec)
	{
		cout << c << " ";
	}
	cout << endl;

	cout << "duration=" << time << endl;

	system("pause");

}
