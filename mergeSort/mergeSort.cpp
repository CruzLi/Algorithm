// mergeSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
#define CUT_OFF 10

using namespace std;


class Solution {
public:
	void mergeSort(vector<int> &a){
		vector<int> aux(a);
		mSort(aux, a, 0, a.size() - 1);
	}

	void merge(vector<int> &src, vector<int> &dst, int lo, int mid, int hi)
	{
		int i = lo, j = mid + 1;
		for (int k = lo; k <= hi; k++)
		{
			if (i > mid) dst[k] = src[j++];
			else if (j > hi) dst[k] = src[i++];
			else if (src[j] < src[i]) dst[k] = src[j++];
			else dst[k] = src[i++];
		}
	}

	void mSort(vector<int> &src, vector<int> &dst, int lo, int hi) {
		if (hi <= lo) return;
		//小规模数组使用插入排序
		if (hi <= lo + CUT_OFF) {
			insertSort(dst, lo, hi);
			return;
		}
		int mid = lo + (hi - lo) / 2;
		mSort(dst, src, lo, mid);
		mSort(dst, src, mid + 1, hi);
		if (src[mid] <= src[mid + 1]) 
			{ dst.assign(src.begin(), src.end()); return; }
		merge(src, dst, lo, mid, hi);
	}

	void insertSort(vector<int> &a, int lo, int hi)
	{
		int i, j;
		for (i = lo; i <= hi; i++)
		{
			int min = a[i];
			for (j = i; j > lo && min < a[j - 1]; j--)
				a[j] = a[j - 1];
			a[j] = min;
		}
	}
	//static vector<int> aux;
};

//vector<int> Solution::aux;

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

	s.mergeSort(vec);
	
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
