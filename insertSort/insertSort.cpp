// insertSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	//内循环通过交换最小元素实现
	/*void insertSort(vector<int> &vec)
	{
		for (int i = 1; i < vec.size(); i++)
		{
			for (int j = i; j > 0 && vec[j] < vec[j - 1]; j--)
			{
				swap(vec[j - 1], vec[j]);
			}
		}
	}
	*/
	//通过右移最大元素实现插入排序
	void insertSort(vector<int> &vec)
	{
		int i, j;
		for (i = 1; i < vec.size(); i++)
		{
			int min = vec[i];
			for (j = i; j > 0 && min < vec[j - 1]; j--)
			{
				vec[j] = vec[j - 1];
			}
			vec[j] = min;
		}
	}
};


int main()
{
	vector<int> vec{ 3, 7, 1, 5, 9, 2, 6, 4, 8, 15 };
	Solution s;
	s.insertSort(vec);
	for (auto c : vec)
	{
		cout << c << " ";
	}
	cout << endl;

	system("pause");

}