#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char **argv) {
	vector<int> array(argc - 1);
	for (size_t i = 0; i < argc - 1; i++)
	{
		array[i] = atoi(argv[i + 1]);
	}
	vector<int> copy;
	copy = array;
	sort(array.begin(), array.end());
	for (size_t i = 0; i < array.size(); i++)
	{
		for (size_t j = 0; j < array.size(); j++)
		{
			if (copy[i] == array[j]) {
				cout << j + 1 << ' ' ;
				break;
			}
		}	
	}
	cout << endl;
}