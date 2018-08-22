#include <iostream>
#include <vector>

using namespace std;
class Solution{
public:
	void selectSort(vector<int> &vec)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			//将vec[i]与vec[i+1....N]中最小的元素交换
			int min = i;
			for (int j = i + 1; j < vec.size(); j++)
				if (vec[j] < vec[min]) min = j;
			swap(vec[i], vec[min]);
		}
	}
};


int main()
{
	vector<int> vec{ 3, 7, 1, 5, 9, 2, 6 };
	Solution s;
	s.selectSort(vec);
	for (auto c : vec)
	{
		cout << c << " ";
	}
	cout << endl;

	system("pause");

}