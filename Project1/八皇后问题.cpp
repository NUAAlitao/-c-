#include<iostream>
using namespace std;

#define MAX 8

class Queen{
private:
	int queens[MAX];
	int number = 1;
public:
	void printResult() {
		cout << "Result " << number << " : " << endl;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if (queens[i] == j) {
					cout << "1 ";
				} else {
					cout << "0 ";
				}
			}
			cout << endl;
		}
		number++;
	}

	void setQueen(int n);
	bool isValid(int n);
};

void Queen::setQueen(int n) {
	for (int i = 0; i < MAX; i++) {
		if (n == 8) {
			printResult();
			return;
		}
		queens[n] = i;
		if (isValid(n)) {
			setQueen(n + 1);
		}
	}
}

bool Queen::isValid(int n) {
	for (int i = 0; i < n; i++) {
		if (queens[i] == queens[n]) {
			return false;
		}
		if (abs(queens[i] - queens[n]) == (n - i)) {
			return false;
		}
	}
	return true;
}

int main() {
	Queen queenTemp;
	queenTemp.setQueen(0);
	system("pause");
}