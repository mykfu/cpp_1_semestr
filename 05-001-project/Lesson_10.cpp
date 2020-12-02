#include<iostream>
#include<algorithm>
using namespace std;

void swap(int& a, int& b) {
	int t = b;
	b = a;
	a = t;
}

int countSameLetters(const string& left, const string& right) {
	int counter = 0;
	for (int i = 0; i < min(left.size(), right.size()); i++)
	{
		if (left[i] == right[i]) counter++;
	}

	return counter;
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

void bubbleSort(string by, string*& arr, int length) {
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (countSameLetters(by, arr[j]) < countSameLetters(by, arr[j + 1])) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int part(int*& arr, int left, int right) {
	int pivot = arr[right];

	for (int i = left; i < right; i++)
	{
		if (arr[i] <= pivot) {
			swap(arr[left++], arr[i]);
		}
	}
	swap(arr[left], arr[right]);
	return left;
}

void quickSort(int*& arr, int left, int right) {
	if (left < right) {
		int p = part(arr, left, right);
		quickSort(arr, left, p - 1);
		quickSort(arr, p + 1, right);
	}
}

void quickSort(int*& arr, int length) {
	quickSort(arr, 0, length - 1);
}

int main8() {

	int length = 10;
	int* arr = new int[length];
	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % 100;
		cout << " " << arr[i];
	}
	cout << endl;
	//bubbleSort(arr, length);
	quickSort(arr, length);
	for (int i = 0; i < length; i++)
	{
		cout << " " << arr[i];
	}
	cout << endl;

	string* strs = new string[4]{ "asdf", "fdas", "fdsa", "fooo" };
	bubbleSort("fdsd", strs, 4);

	for (int i = 0; i < 4; i++)
	{
		cout << " " << strs[i];
	}

	return EXIT_SUCCESS;
}