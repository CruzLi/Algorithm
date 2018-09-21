// heapSort.cpp : �������̨Ӧ�ó������ڵ㡣
//

// fastSort.cpp : �������̨Ӧ�ó������ڵ㡣
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

		//�Ľ������³����ϸ�
		while (N > 0)
		{
			int temp = a[N - 1];
			a[N - 1] = a[0]; a[0] = 0; N--; //�����Ԫ�ط�������ĩβ�������г��ȼ�1��
			int k = 0; //���ڵ� 
			int j = 2 * k + 1;//���ӽڵ�
			while (j <= N - 1)
			{
				if (j < N - 1 && a[j] < a[j + 1]) j++; 
				a[k] = a[j]; //���ӽڵ��нϴ�Ľ��������ڵ�
				k = j; j = 2 * k + 1;
			}

			a[k] = temp; //�Ѷ�βԪ�ط����ȱ�ڵ�
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
		//��Ϊ���ڵ㲻�Ǵ��㿪ʼ�����Ը��ڵ������������ֿ���
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
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  

	s.heapSort(vec);

	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  

	cout << "final data:" << endl;
	for (auto c : vec)
	{
		cout << c << " ";
	}
	cout << endl;

	cout << "duration=" << time << endl;

	system("pause");

}
