#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<set>
using namespace std;

/**
 *������ȱ���ͼ�ĵݹ麯��
 *@param graph ͼ���ڽӱ�
 *@param discovered �����ֵĽڵ��set����
 *@param currentNode ��ǰ̽���Ľڵ�
*/
void dfsHandler(vector<list<int>>& graph, set<int>& discovered, int currentNode) {
	list<int>::iterator it = graph[currentNode].begin();
	for (; it != graph[currentNode].end(); it++) {
		if (discovered.count(*it) == 0) {
			discovered.insert(*it);
			cout << "found " << *it << " from " << currentNode << endl;
			dfsHandler(graph, discovered, *it);
		}
	}
}

/**
 *������ȱ���ͼ�е����нڵ�
 *@param graph ͼ���ڽӱ�
 *@param start ��ʼ�����Ľڵ�
*/
void dfs(vector<list<int>>& graph, int start) {
	set<int> discovered;
	discovered.insert(start);
	dfsHandler(graph, discovered, start);
}

/**
 *������ȱ���ͼ�е����нڵ�
 *@param graph ͼ���ڽӱ�
 *@param start ��ʼ�����Ľڵ�
*/
void bfs(vector<list<int>>& graph, int start) {
	set<int> discovered;
	queue<int> notExplored;

	notExplored.push(start);
	discovered.insert(start);
	while (!notExplored.empty()) {
		int currentNode = notExplored.front();
		notExplored.pop();
		list<int>::iterator it = graph[currentNode].begin();
		for (; it != graph[currentNode].end(); it++) {
			if (discovered.count(*it) == 0) {
				notExplored.push(*it);
				discovered.insert(*it);
				cout << "found " << *it << " from " << currentNode << endl;
			}
		}
	}

}

int main() {
	vector<list<int>> graph(7, list<int>());
	graph[0].push_back(1);
	graph[0].push_back(2);

	graph[1].push_back(0);
	graph[1].push_back(2);

	graph[2].push_back(0);
	graph[2].push_back(1);
	graph[2].push_back(3);
	graph[2].push_back(4);

	graph[3].push_back(2);
	graph[3].push_back(4);
	graph[3].push_back(5);

	graph[4].push_back(2);
	graph[4].push_back(3);
	graph[4].push_back(5);
	graph[4].push_back(6);

	graph[5].push_back(3);
	graph[5].push_back(4);

	graph[6].push_back(4);

	cout << "BFS:" << endl;
	bfs(graph, 4);

	cout << "DFS:" << endl;
	dfs(graph, 4);

	system("pause");
}