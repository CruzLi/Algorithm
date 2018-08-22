// shellSort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	//��ѭ��ͨ��������СԪ��ʵ��
	/*void shellSort(vector<int> &vec)
	{
		int h = 1;
		while (h < vec.size() / 3) h = 3 * h + 1;
		while (h >= 1)
		{
			for (int i = 1; i < vec.size(); i++)
			{
				for (int j = i; j >= h && vec[j] < vec[j - h]; j -= h)
				{
					swap(vec[j - h], vec[j]);
				}
			}
			h = h / 3;
		}
	}
	*/
	//ͨ���������Ԫ��ʵ�ֲ�������
	void shellSort(vector<int> &vec)
	{
		int h = 1;
		while (h < vec.size() / 3) h = h * 3 + 1;
		int i, j;
		while (h >= 1)
		{
			for (i = h; i < vec.size(); i++)
			{
				int min = vec[i];
				for (j = i; j >= h && min < vec[j - h]; j -= h)
				{
					vec[j] = vec[j - h];
				}
				vec[j] = min;
			}

			h = h / 3;
		}
	}
};


int main()
{
	vector<int> vec{ 3, 7, 1, 5, 9, 2, 6, 4, 8, 15 };
	Solution s;
	s.shellSort(vec);
	for (auto c : vec)
	{
		cout << c << " ";
	}
	cout << endl;

	system("pause");

}
