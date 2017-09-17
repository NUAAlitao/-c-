#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

struct Node{
	int weight;
	char value;
	struct Node *left, *right;
};

struct weightLocation{
	int weight, location;
};

/**
 *建立Huffman树
 * @param HuffTree 树根
 * @param Nodes 节点数组
 */
void buildHuffTree(struct Node * &HuffTree, vector<struct Node*> &Nodes) {
	struct weightLocation minFirst, minSecond;
	while (Nodes.size() > 1) {
		//初始默认第一个和第二个node是最小的两个
		if (Nodes.at(0)->weight > Nodes.at(1)->weight) {
			minFirst.weight = Nodes.at(1)->weight;
			minFirst.location = 1;
			minSecond.weight = Nodes.at(0)->weight;
			minSecond.location = 0;
		} else {
			minFirst.weight = Nodes.at(0)->weight;
			minFirst.location = 0;
			minSecond.weight = Nodes.at(1)->weight;
			minSecond.location = 1;
		}
		for (int i = 2; i < Nodes.size(); i++) {
			if (Nodes.at(i)->weight <= minFirst.weight) {
				minSecond = minFirst;
				minFirst.weight = Nodes.at(i)->weight;
				minFirst.location = i;
			} else if (Nodes.at(i)->weight < minSecond.weight) {
				minSecond.weight = Nodes.at(i)->weight;
				minSecond.location = i;
			}
		}
		struct Node *nodeTemp = new struct Node;
		nodeTemp->left = Nodes.at(minFirst.location);
		nodeTemp->right = Nodes.at(minSecond.location);
		nodeTemp->weight = minFirst.weight + minSecond.weight;
		Nodes.push_back(nodeTemp);
		vector<struct Node*>::iterator it = Nodes.begin();
		for (int i = 0; it != Nodes.end(); i++) {
			if ((i == minFirst.location) || (i == minSecond.location)) {
				it = Nodes.erase(it);
				continue;
			}
			it++;
		}		
	}
	HuffTree = Nodes.at(0);
}

/**
 *获取每个叶子节点的编码
 * @param TreeRoot Huffman树根节点
 * @param encoding 当前节点的父节点的编码
 * @param codes 存储编码的map
 */
void getLeafCode(struct Node *TreeRoot, string encoding, map<char,string> &codes) {
	if ((TreeRoot->left == NULL) && (TreeRoot->right == NULL)) {
		char value = TreeRoot->value;
		codes.insert(pair<char,string>(value, encoding));
	} else {
		if (TreeRoot->left != NULL) {
			getLeafCode(TreeRoot->left, encoding+'0', codes);
		} 
		if (TreeRoot->right != NULL) {
			getLeafCode(TreeRoot->right, encoding+'1', codes);
		}
	}
}

/**
 *计算所有字符（每个叶子节点）的Huffman编码
 * @param HuffTree huffman树根节点
 * @param codes 存储编码的map
 */
void getHuffCode(struct Node *HuffTree, map<char, string> &codes) {
	string encoding = "";
	getLeafCode(HuffTree, encoding, codes);
}

/**
 *对输入的串编码
 *@param input 输入串
 *@param codes 存储编码的map
 */
string encoding(string input, map<char, string> &codes) {
	map<char, string>::iterator itr;
	string code_str = "";
	for (int i = 0; i < input.length(); i++) {
		itr = codes.find(input[i]);
		code_str.append((*itr).second);
	}
	return code_str;
}

/**
 *对输入的编码串解码
 * @param input 输入的编码串
 * @param TreeRoot Huffman树根节点
 */
void decoding(string &input, struct Node *TreeRoot) {
	char tempC = input[0];
	
	if ((TreeRoot->left == NULL) && (TreeRoot->right == NULL)) {
		char value = TreeRoot->value;
		cout << value;
		return;
	}
	input = input.substr(1);
	if (TreeRoot->left != NULL && tempC == '0' ) {
		decoding(input, TreeRoot->left);
	}
	if (TreeRoot->right != NULL && tempC == '1') {
		decoding(input, TreeRoot->right);
	}
	
}

int main() {
	struct Node *HuffTree = NULL;
	vector<struct Node*> Nodes;
	map<char, string> codes;

	int nodeNum;
	int weight;
	char value;
	cin >> nodeNum;
	for (int i = 0; i < nodeNum; i++) {
		cin >> value;
		cin >> weight;
		struct Node *temp = new struct Node;
		temp->left = NULL;
		temp->right = NULL;
		temp->value = value;
		temp->weight = weight;
		Nodes.push_back(temp);
	}

	buildHuffTree(HuffTree, Nodes);
	getHuffCode(HuffTree, codes);
	cout << "The codes is:" << endl;
	map<char, string>::iterator itCodes = codes.begin();
	for (; itCodes != codes.end(); itCodes++) {
		cout << itCodes->first << ": " << (*itCodes).second << endl;
	}

	cout << "Please input a string of contain（a-g）: ";
	string input, coding;
	cin >> input;
	coding = encoding(input, codes);
	cout << "The encoding is : " << coding << endl;
	cout << "The decoding is: ";
	while (coding.length() > 0) {
		decoding(coding, HuffTree);
	}
	cout << endl;
	cout << "Please input a string of encoding : ";
	cin >> input;
	cout << "The decoding is: ";
	while (input.size() > 0) {
		decoding(input, HuffTree);
	}
	cout << endl;

	system("pause");
}