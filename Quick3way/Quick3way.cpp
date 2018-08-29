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
		int lt = lo, i = lo + 1, gt = hi;
		int v = a[lo];
		while (i <= gt)
		{
			if (a[i] < v) swap(a[lt++], a[i++]);
			else if (a[i] > v) swap(a[i], a[gt--]);
			else i++;
		}
		sort(a, lo, lt - 1);
		sort(a, gt + 1, hi);
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
	for (int i = N; i < 3 * N/2; i++)
	{    
		vec.push_back(i - N);
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
