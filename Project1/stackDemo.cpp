#include<iostream>
#include<stack>
using namespace std;

int main(){
	stack<char> st;
	char temp;
	
	while ((cin>>temp) &&( temp!='#')){
		if (temp != ')'){
			st.push(temp);
		}
		else{
			while ((st.size() != 0) && (st.top() != '('))
				st.pop();
			if (st.size() == 0){
				cout << "failed" << endl;
				system("pause");
				return 0;
			}
			st.pop();
			continue;
		}
	}
	if (st.size() == 0){
		cout << "success" << endl;
	}
	else{
		cout << "failed" << endl;
	}
	system("pause");
}