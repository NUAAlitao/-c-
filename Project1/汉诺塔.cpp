#include<iostream>
using namespace std;

int step = 1;
void move(int n, char a, char b) {
	cout << step++ << ": move " << n << " from " << a << " to " << b << endl;
}

void hannoi(int n, char a, char b, char c) {
	if (n == 1) {
		move(1, a, c);
	} else {
		hannoi(n - 1, a, c,b);
		move(n, a, c);
		hannoi(n - 1, b, a, c);
	}
}
int main() {
	int n;
	cin >> n;
	hannoi(n, 'a', 'b', 'c');
	system("pause");
}