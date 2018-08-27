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
	void fastSort(vector<int> &a)
	{
		random_shuffle(a.begin(), a.end());

		int maxIndex = 0;
		for (int i = 0; i < int(a.size()); i++)
		{
			if (a[maxIndex]< a[i])
				maxIndex = i;
		}
		swap(a[maxIndex], a[a.size() - 1]);
		sort(a, 0, a.size() - 1);
	}

	void sort(vector<int> &a, int lo, int hi)
	{	
		if (hi <= lo) return;
		if (hi <= lo + M) { insert(a, lo, hi); return; }
		int j = partition(a, lo, hi);
		sort(a, lo, j - 1);
		sort(a, j + 1, hi);
	}

	int getRandom(vector<int> &a, int lo, int hi)
	{
		int p = (rand() % (hi-lo+1))+ lo; 
		swap(a[lo], a[p]);
		return a[lo];
	}

	int selectMiddle(vector<int> &a, int lo, int hi)
	{
		int middle = lo + (hi - lo) / 2;

		if (a[lo] > a[hi])
			swap(a[lo], a[hi]);
		if (a[middle] > a[hi])
			swap(a[middle], a[hi]);
		if (a[middle] > a[lo])
			swap(a[lo], a[middle]);
		return a[lo];
	}

	int partition(vector<int> &a, int lo, int hi)
	{
		int i = lo, j = hi + 1;
		//int v = a[lo];
		int v = getRandom(a, lo, hi);// 通过随机数保证取得的基准元素的随机性
		//int v = selectMiddle(a, lo, hi); //三数取中法
		while (true)
		{
			while (a[++i] < v);
			while (v < a[--j]);
			if (i >= j) break;
			swap(a[i], a[j]);
		}
		swap(a[lo], a[j]);
		return j;
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

	Solution s;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时  

	s.fastSort(vec);

	QueryPerformanceCounter(&nEndTime);//停止计时  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  

	for (auto c : vec)
	{
		cout << c << " ";
	}
	cout << endl;

	cout << "duration=" << time << endl;

	system("pause");

}
