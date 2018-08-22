// mergeSortDtoU.cpp : �������̨Ӧ�ó������ڵ㡣
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
		//����logN�����ݹ�
		int N = a.size();
		for (int sz = 1; sz < N; sz += sz) {    //sz�������С
			for (int lo = 0; lo < N - sz; lo += sz + sz) //lo:����������
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
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  

	s.mergeSort(vec);

	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  

	for (auto c : vec)
	{
		cout << c << " ";
	}
	cout << endl;

	cout << "duration=" << time << endl;

	system("pause");

}

