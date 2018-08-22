#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> & vec)
{
	bool sorted = false;
	int n = vec.size();
	while (!sorted) {
		sorted = true;
		for (int i = 1; i < n; i++)
		{
			if (vec[i] < vec[i - 1])
			{
				swap(vec[i], vec[i - 1]);
				sorted = false;
			}
		}
		n--;//至此末元素必然就位，故可以缩短待排序序列的有效长度
	}
}

int main()
{
	vector<int> vec{ 3, 5, 1, 5, 9, 2, 6 };
	bubbleSort(vec); 
	for (auto c : vec)
	{
		cout << c << " ";
	}
	cout << endl;

	system("pause");

}