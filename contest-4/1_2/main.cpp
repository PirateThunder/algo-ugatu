// ID: 66227942
// https://contest.yandex.ru/contest/35212/problems/1/

#include <iostream>
#include <string>
using namespace std;

unsigned int h1(const string s, const unsigned int m, const unsigned int a = 1103) {
	unsigned int h = 0;
	for (auto c : s) {
		h = (h * a + c) % m;
	}
	return h;
}

class HashTable {
private:
	string* data;
	unsigned int size;
	unsigned int total;
	void increase() {
		string* tmp = data;
		size *= 2;
		total = 0;
		data = new string[size];
		for (size_t i = 0; i < size; i++) {
            data[i] = "";
		}
		for (size_t i = 0; i < size / 2; i++) {
			if (tmp[i] != "" && tmp[i] != "D") {
				_push(tmp[i]);
			}
		}
		delete[] tmp;
	}
public:
	HashTable() : data(new string[8]), size(8), total(0) {
		for (size_t i = 0; i < size; i++) {
			data[i] = "";
		}
	}
	~HashTable() {
		delete[] data;
	}
	bool _push(const string elem) {
		if (total == 3 * (size >> 2)) {
			increase();
		}
		unsigned int hash = h1(elem, size);
		const unsigned int step_of_samp = ((h1(elem, size, 331) << 1) + 1) % size;
		unsigned int num_of_samp = 0;
		while (num_of_samp <= total && data[hash] != elem) {
			if (data[hash] == "") {
				data[hash] = elem;
				total++;
				return true;
			}
			else {
				num_of_samp++;
				hash = (hash + step_of_samp) % size;
			}
		}
		return false;
	}
	bool _erase(const string elem) {
		unsigned int hash = h1(elem, size);
		const unsigned int step_of_samp = ((h1(elem, size, 331) << 1) + 1) % size;
		unsigned int num_of_samp = 0;
		while (num_of_samp <= total) {
			if (data[hash] == "") {
				return false;
			}
			else if (data[hash] == elem) {
				data[hash] = "D";
				return true;
			}
			else {
				num_of_samp++;
				hash = (hash + step_of_samp) % size;
			}
		}
		return false;
	}
	bool _search(const string elem) {
		unsigned int hash = h1(elem, size);
		const unsigned int step_of_samp = ((h1(elem, size, 331) << 1) + 1) % size;
		unsigned int num_of_samp = 0;
		while (num_of_samp <= total && data[hash] != "") {
			if (data[hash] == elem) {
				return true;
			}
			else {
				num_of_samp++;
				hash = (hash + step_of_samp) % size;
			}
		}
		return false;
	}
};

int main() {
	HashTable hashTable;
	string elem;
	char c;
	while (cin >> c && cin >> elem) {
		if (elem == "") {
            break;
		}
		if (c == '+') {
			cout << ((hashTable._push(elem)) ? "OK" : "FAIL") << "\n";
		}
		else if (c == '-') {
			cout << ((hashTable._erase(elem)) ? "OK" : "FAIL") << "\n";
    	}
		else if (c == '?') {
			cout << ((hashTable._search(elem)) ? "OK" : "FAIL") << "\n";
		}
	}
	return 0;
}
