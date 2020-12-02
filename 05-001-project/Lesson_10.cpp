#include<iostream>
using namespace std;

void swap(int& a, int& b) {
	int t = b;
	b = a;
	a = t;
}
 
void bubbleSort(int*& arr, int length) {
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int main() {

	int length = 10;
	int* arr = new int[length];
	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % 100;
		cout << " " << arr[i];
	}
	cout << endl;
	bubbleSort(arr, length);
	for (int i = 0; i < length; i++)
	{
		cout << " " << arr[i];
	}




}