#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
//
//bool in_array(int findMe, int* arr, int length) {
//
//	//bool flag = false;
//
//	for (int i = 0; i < length; i++)
//	{
//		if (arr[i] == findMe) {
//			//flag = true;
//			//break;
//			return true;
//		}
//	}
//	return false;
//	//return flag;
//}
//
//bool in_array(string findMe, string* arr, int length) {
//
//	for (int i = 0; i < length; i++)
//	{
//		if (arr[i] == findMe) {
//			return true;
//		}
//	}
//	return false;
//}

template<typename T>
bool in_array(T findMe, T* arr, int length) {

	for (int i = 0; i < length; i++)
	{
		if (arr[i] == findMe) {
			return true;
		}
	}
	return false;
}


// 73
// { 1, 4, 5, 7, 8, 19, 42, 56, 69, 73 };
// (((2^31-1)/2 + 1) + 2^31-2 ) / 2
bool binary_search(int findMe, int* arr, int length) {
	int left = 0;
	int right = length - 1;

	while (left <= right) {
		//int middle = (right + left) / 2; wrong
		int middle = left + (right - left) / 2;
		if (arr[middle] < findMe) {
			left = middle + 1;
		}
		else if (arr[middle] > findMe) {
			right = middle - 1;
		}
		else {
			return true;
		}
	}

	return false;
}

// left < right => compareStrings(left, right) = -1
// left == right => compareStrings(left, right) = 0
// left > right => compareStrings(left, right) = 1
//
// asdf bfds
// asd asdf = -1
// asdfd asdf = 1
// fdsa fdsb
int compareStrings(string left, string right) {

	int length = min(left.length(), right.length());
	string abc = "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ";
	// todo
	for (int i = 0; i < length; i++)
	{
		unsigned char c1 = (left.at(i)) * 2;
		unsigned char c2 = (right.at(i)) * 2;
		if ((left.at(i)) == '¸') {
			c1 = 'å' * 2 + 1;
		}
		
		if ((right.at(i)) == '¸') {
			c2 = 'å' * 2 + 1;
		}

		//if (c1 != c2) return c1 - c2;

		if (c1 < c2) {
			return -1;
		}
		
		if (c1 > c2) {
			return 1;
		}
	}
	//return left.length() - right.length();
	if (left.length() < right.length()) return -1;
	else if (left.length() > right.length()) return 1;

	return 0;
}


bool binary_search(string findMe, string* arr, int length) {
	int left = 0;
	int right = length - 1;

	while (left <= right) {
		int middle = (right + left) / 2;
		//if (arr[middle] < findMe) {
		if (compareStrings(arr[middle], findMe) < 0) {
			left = middle + 1;
		}
		//else if (arr[middle] > findMe) {
		else if (compareStrings(arr[middle], findMe) > 0) {
			right = middle - 1;
		}
		else {
			return true;
		}
	}

	return false;
}

int main6() {
	setlocale(LC_ALL, "rus");

	int length = 10;
	int* arr = new int[length];

	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % 100;
		cout << " " << arr[i];
	}
	cout << endl;

	int findMe = 0;

	if (in_array(findMe, arr, length))
		cout << "FOUND!!!\n";
	else
		cout << "NOT FOUND!!!\n";

	if (in_array(123, arr, length))
		cout << "FOUND!!!\n";
	else
		cout << "NOT FOUND!!!\n";

	string* strs = new string[4]{ "asdf", "asd", "fd", "123" };

	if (in_array(string("fd"), strs, length))
		cout << "FOUND!!!\n";
	else
		cout << "NOT FOUND!!!\n";

	// find 73
	int* sortedArr = new int[10] {1, 4, 5, 7, 8, 19, 42, 56, 69, 73};
	cout << "binary \n";
	if (binary_search(73, sortedArr, length))
		cout << "FOUND!!!\n";
	else
		cout << "NOT FOUND!!!\n";

	cout << "binary_search string(fd):\n";
	string* strs2 = new string[5]{ "123", "asd", "asdf", "fd", "kll"};
	if (binary_search(string("fd"), strs2, length))
		cout << "FOUND!!!\n";
	else
		cout << "NOT FOUND!!!\n";

	cout << "binary_search string(¸æ):\n";
	string* strs3 = new string[5]{ "åå", "å¸", "¸æ", "¸ëêè", "ñòîë"};
	if (binary_search(string("¸æ"), strs3, length))
		cout << "FOUND!!!\n";
	else
		cout << "NOT FOUND!!!\n";

	cout << "compareStrings(asdf, bsdf): expected = -1, actual = " << compareStrings("asdf", "bsdf") << endl;
	cout << "compareStrings(bsdf, bsdf): expected = 0, actual = " << compareStrings("bsdf", "bsdf") << endl;
	cout << "compareStrings(bsdf, asdf): expected = 1, actual = " << compareStrings("bsdf", "asdf") << endl;

	cout << "compareStrings(¸, å): expected = 1, actual = " << compareStrings("¸", "å") << endl;
	cout << "compareStrings(æ, ¸): expected = 1, actual = " << compareStrings("æ", "¸") << endl;


	return 0;
}