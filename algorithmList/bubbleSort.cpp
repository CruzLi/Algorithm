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
		n--;//����ĩԪ�ر�Ȼ��λ���ʿ������̴��������е���Ч����
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