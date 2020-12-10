#include<iostream>
#include<fstream>
#include<string>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

string* dict;
int dictLength = 0;

string* history;
int histSize = 0;


bool in_array(string findMe, string* arr, int length) {

	for (int i = 0; i < length; i++)
	{
		if (arr[i] == findMe) {
			return true;
		}
	}
	return false;
}

void readDictionary(const char* filename) {
	setlocale(LC_ALL, "ru_RU");
	ifstream file(filename);

	if (file.is_open()) {
		char* line = new char();
		
		while (file.getline(line, 6)) {
			dictLength++;
		}
		cout << dictLength << endl;

		dict = new string[dictLength];

		file.clear();
		file.seekg(0);

		for (int i = 0; file.getline(line, 6); i++)
		{
			dict[i] = line;
			//cout << dict[i] << endl;
		}
		file.close();
	}
}

void add(string*& strs, int& size, string newValue) {
	string* result = new string[size + 1];

	for (int i = 0; i < size; i++)
	{
		result[i] = strs[i];
	}
	result[size] = newValue;
	size++;
	strs = result;
}

void print(string* strs, int& size) {
	cout << "[";
	for (int i = 0; i < size; i++)
	{
		cout << strs[i] << (i < size - 1 ? ", " : "");
	}
	cout << "]\n";
}

int compareStrings(const string& left, const string& right) {

	int length = min(left.length(), right.length());
	string abc = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	// todo
	for (int i = 0; i < length; i++)
	{
		unsigned char c1 = (left.at(i)) * 2;
		unsigned char c2 = (right.at(i)) * 2;
		if ((left.at(i)) == 'ё') {
			c1 = 'е' * 2 + 1;
		}

		if ((right.at(i)) == 'ё') {
			c2 = 'е' * 2 + 1;
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

bool binary_search(string& findMe, string*& arr, int length) {
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

string* generateWords(string& in, string& out, int& size) {
	add(history, histSize, in);
	string abc = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	int count = 0;
	//int size = 0;
	string* result = new string[size];
	for (int i = 0; i < in.size(); i++)
	{
		string current = in;
		if (current[i] != out[i]) {
			for (int j = 0; j < abc.length(); j++)
			{
				current[i] = abc[j];
				//current.replace(i, 1, abc.substr(j, 1));
				if (current != in &&
					!in_array(current, history, histSize)
					&& binary_search(current, dict, dictLength)) {
					add(result, size, current);
					add(history, histSize, current);
				}
			}
		}
	}
	return result;
}

bool found = false;

void bubbleSort(string by, string*& arr, int length);

void game(string& in, string& out, string* chain, int chain_length) {

	if (in == out) {
		cout << out << endl;
		add(chain, chain_length, in);
		cout << "Цепочка найдена!\n";
		found = true;
		print(chain, chain_length);
		cout << "Размер цепочки = " << chain_length << endl;
		return;
	}

	cout << in << ": ";

	int size = 0;

	string* newWords = generateWords(in, out, size);
	bubbleSort(out, newWords, size);

	if (size > 0) {
		add(chain, chain_length, in);
	}
	
	print(newWords, size);

	for (int i = 0; i < size; i++)
	{
		if (!found) {
			game(newWords[i], out, chain, chain_length);
		}
	}

}

void game(string& in, string& out) {

	string* chain = new string[0];
	int chain_length = 0;

	game(in, out, chain, chain_length);
}

struct Pair
{
	string parent;
	string child;
};

void reverse(queue<string>& que) {
	stack<string> stk;

	while (!que.empty()) {
		string current = que.front();
		que.pop();
		stk.push(current);
	}

	while (!stk.empty()) {
		string current = stk.top();
		stk.pop();
		que.push(current);
	}
}


void gameBFS(string& in, string& out) {
	
	queue<string> que;
	que.push(in);

	vector<Pair> result;

	while (!que.empty()) {
		string current = que.front();
		que.pop();

		if (current == out) {
			cout << out << endl;
			cout << "Цепочка найдена!\n";
			found = true;
			queue<string> ans;
			ans.push(out);
			string cur = out;
			for (int i = 0; i < result.size() && cur != in; i++)
			{
				if (result.at(i).child == cur) {
					ans.push(cur = result.at(i).parent);
					i = 0;
				}
			}

			ans.push(in);
			reverse(ans);

			cout << "Размер цепочки = " << ans.size() << endl;

			while (!ans.empty()) {
				string current2 = ans.front();
				ans.pop();
				cout << " " << current2;
			}
			cout << endl;

			return;
		}


		int size = 0;
		string* newWords = generateWords(current, out, size);
		bubbleSort(out, newWords, size);

		cout << current << ": ";
		print(newWords, size);


		for (int i = 0; i < size; i++)
		{
			que.push(newWords[i]);
			Pair p = { current, newWords[i] };
			result.push_back(p);
		}
	}


}

int main() {
	readDictionary("dict_len4_ansi.txt");

	string in = "муха";
	string out = "слон";

	//game(in, out);
	gameBFS(in, out);


	return 0;
}