#include<iostream>
#include<vector>
#include <queue>
#include <stack>

using namespace std;

template<typename T>
struct MyStruct
{
	T t;
};


template<typename T>
void print(queue<T> que) {
	cout << "Queue@[";
	while (!que.empty()) {
		T current = que.front();
		que.pop();
		cout << " " << current;
	}
	cout << "]" << endl;
}

template<typename T>
void print_(stack<T> stk) {
	if (stk.empty()) return;

	T current = stk.top();
	stk.pop();
	print_(stk);
	cout << " " << current;
}

template<typename T>
void print(stack<T> stk) {
	cout << "Stack@[";
	print_(stk);
	cout << "]" << endl;
}

void reverse(queue<int>& que) {
	stack<int> stk;

	while (!que.empty()) {
		int current = que.front();
		que.pop();
		stk.push(current);
	}

	while (!stk.empty()) {
		int current = stk.top();
		stk.pop();
		que.push(current);
	}
}

int main78() {
	// STL 

	MyStruct<int> ms;

	vector<int> vec;

	for (int i = 1; i <= 10; i++)
	{
		vec.push_back(i * 10);
	}

	for (int i = 0; i < vec.size(); i++)
	{
		cout << " " << vec[i] << " " << vec.at(i);
	}
	cout << endl;

	for (auto n : vec) {
		cout << " " << n;
	}
	cout << endl;

	queue<int> que; // FIFO

	for (int i = 1; i <= 10; i++)
	{
		que.push(i * 10);
	}

	print(que);

	stack<int> stk; // LIFO

	for (int i = 1; i <= 10; i++)
	{
		stk.push(i * 10);
	}

	print(stk);
	
	
	reverse(que);
	print(que);



	return 0;
}