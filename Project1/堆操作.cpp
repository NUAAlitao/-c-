#include<iostream>
#include<vector>
using namespace std;

template<class T>
class MaxHeap{
private:
	int size;
	vector<T> body;

public:
	MaxHeap() {
		body.push_back(0);
	}

	int getSize() {
		return size;
	}

	void push(T element) {
		body.push_back(element);
		size++;
	}

	/**
	 *返回堆顶元素
	*/
	T getTop() {
		T temp = body[1];
		body[1] = body[size];
		size--;
		return temp;
	}

	/**
	*调整树结构，使其成为最大堆
	*/
	void adjust() {
		for (int i = size / 2; i >= 1;i--) {
			adjust(i);
		}
	}

	/**
	 *调整树结构，使其成为最大堆
	 *@param root 当前调整的树根节点索引
	*/
	void adjust(int root) {
		if ((2 * root + 1) <= size) {
			int maxIndex = 2 * root;
			if (body[2 * root] < body[2 * root + 1]) {
				maxIndex = 2*root+1;
			}
			if (body[root] < body[maxIndex]) {
				T temp = body[root];
				body[root] = body[maxIndex];
				body[maxIndex] = temp;
				adjust(maxIndex);
			}
		} else if ((2 * root) <= size) {
			if (body[root] < body[2 * root]) {
				T temp = body[root];
				body[root] = body[2 * root];
				body[2 * root] = temp;
			}
		}
	}
};

template<class T>
class MinHeap{
private:
	int size;
	vector<T> body;

public:
	MinHeap() {
		body.resize(1);
	}

	int getSize() {
		return size;
	}

	void push(T element) {
		body.push_back(element);
		size++;
	}

	/**
	*返回堆顶元素
	*/
	T getTop() {
		T temp = body[1];
		body[1] = body[size];
		size--;
		return temp;
	}

	/**
	*调整树结构，使其成为最小堆
	*/
	void adjust() {
		for (int i = size / 2; i>=1; i--) {
			adjust(i);
		}
	}

	/**
	*调整树结构，使其成为最小堆
	*@param root 当前调整的树根节点索引
	*/
	void adjust(int root) {
		if ((2 * root + 1) <= size) {
			int minIndex = 2 * root;
			if (body[2 * root] > body[2 * root + 1]) {
				minIndex = 2 * root + 1;
			}
			if (body[root] > body[minIndex]) {
				T temp = body[root];
				body[root] = body[minIndex];
				body[minIndex] = temp;
				adjust(minIndex);
			}
		} else if ((2 * root) <= size) {
			if (body[root] > body[2 * root]) {
				T temp = body[root];
				body[root] = body[2 * root];
				body[2 * root] = temp;
			}
		}
	}
};

int main() {
	int a;
	double d;
	cout << "input some integer:" << endl;

	MaxHeap<int> maxHeap;
	while (cin >> a) {
		maxHeap.push(a);
	}
	maxHeap.adjust();
	vector<int> a_array;
	while (maxHeap.getSize() > 0) {
		a_array.push_back(maxHeap.getTop());
		maxHeap.adjust(1);
	}
	cout << "integer desc:" << endl;
	vector<int>::iterator it = a_array.begin();
	for (; it != a_array.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	//cout << cin.fail() << cin.bad() << cin.eof() << endl;
	cout << endl << "input some double:" << endl;
	MinHeap<double> minHeap;
	
	cout << cin.fail() << cin.bad() << cin.eof() << endl;
	cin.clear();
	cin.get();

	while (cin >> d) {
		minHeap.push(d);
	}
	minHeap.adjust();
	vector<double> d_array;
	while (minHeap.getSize() > 0) {
		d_array.push_back(minHeap.getTop());
		minHeap.adjust(1);
	}
	cout << "double aesc:" << endl;
	vector<double>::iterator itd = d_array.begin();
	for (; itd != d_array.end(); itd++) {
		cout << *itd << " ";
	}
	cout << endl;
	system("pause");
}