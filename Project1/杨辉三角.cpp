#include<iostream>
#include<queue>
using namespace std;


void calculate(queue<int> &qu1, queue<int> &qu2) {
	int i1 = qu1.front();
	int i2;
	qu1.pop();
	qu2.push(i1);
	while (!qu1.empty()) {
		i2 = qu1.front();
		qu1.pop();
		qu2.push(i1 + i2);
		i1 = i2;
		if (qu1.empty()) {
			qu2.push(i2);
		}
	}
}
void printSpace(int spaceNum) {
	for (int i = 0; i < spaceNum; i++) {
		cout << " ";
	}
}
void printTriangle(int spaceNum, queue<int> &qu1) {
	queue<int> qu2;
	calculate(qu1, qu2);
	qu1 = qu2;
	printSpace(spaceNum);
	queue<int> tempQu(qu2);
	while (!tempQu.empty()) {
		cout << tempQu.front() << " ";
		tempQu.pop();
	}
}
int main(){
	queue<int> qu1, qu2;
	int n;
	cin >> n;
	if (n >= 3) {
		printSpace(n - 1);
		cout << "1" << endl;
		printSpace(n - 2);
		cout << "1 1" << endl;
		qu1.push(1);
		qu1.push(1);
		for (int i = 3; i <= n; i++) {
			printTriangle(n-i,qu1);
			cout << endl;
		}
		cout << endl;
	} else if (n == 1) {
		cout << 1 << endl;
	} else if (n == 2) {
		cout << " 1" << endl;
		cout << "1 1" << endl;
	}
	system("pause");
}