#include<iostream>
#include<cstring>
#include<vector>
#include<list>
#include<set>
using namespace std;

void fun(vector<int> vc1, list<int> &ls1) {
	vc1.push_back(3);
	ls1.push_back(4);
}

int main(){
	vector<int> vc;
	list<int> ls;
	fun(vc, ls);

	cout << vc.size() << endl << ls.size() << endl;
	
	
	system("pause");
}