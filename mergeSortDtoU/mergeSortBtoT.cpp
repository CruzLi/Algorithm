// mergeSortDtoU.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>

using namespace std;

class Solution {
public:
	void mergeSort(vector<int> &a){
		//进行logN两两递归
		int N = a.size();
		for (int sz = 1; sz < N; sz += sz) {    //sz子数组大小
			for (int lo = 0; lo < N - sz; lo += sz + sz) //lo:子数组索引
				merge(a, lo, lo + sz - 1, min(lo + sz + sz - 1, N - 1));
		}
	}

	void merge(vector<int> &a, int lo, int mid, int hi){
		int i = lo, j = mid + 1;
		aux.assign(a.begin(), a.end());
		for (int k = lo; k <= hi; k++)
		{
			if (i > mid)              a[k] = aux[j++];
			else if (j > hi)          a[k] = aux[i++];
			else if (aux[j] < aux[i]) a[k] = aux[j++];
			else                      a[k] = aux[i++];
		}
	}

	static vector<int> aux;
};

vector<int> Solution::aux;

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

