#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;

struct side{
	int nodeFirst, nodeSeconde;
};

/**
 *����ķ�㷨������С������
 *@param graph ͼ���ڽӾ���
 *@param start ��ʼ�ڵ�
*/
void prim(vector<vector<int>> graph, int start) {
	set<int> discovered;
	int minSide, minNodeX, minNodeY;
	discovered.insert(start);
	vector<struct side> sides;

	while (discovered.size() < graph.size()) {
		minSide = INT_MAX;
		set<int>::iterator it = discovered.begin();
		for (; it != discovered.end(); it++) {
			vector<int> distance = graph[*it];
			for (int j = 0; j < distance.size(); j++) {
				if ((distance[j] < minSide) && (discovered.count(j)==0)) {
					minNodeX = *it;
					minNodeY = j;
					minSide = distance[j];
				}//if
			}//for
		}//for
		struct side sideTemp;
		sideTemp.nodeFirst = minNodeX;
		sideTemp.nodeSeconde = minNodeY;
		sides.push_back(sideTemp);
		discovered.insert(minNodeY);
	}//while

	cout << "����ķ�㷨�õ�����С��������" << endl;
	vector<struct side>::iterator it = sides.begin();
	for (; it != sides.end(); it++) {
		cout << "from " << (*it).nodeFirst << " to " << (*it).nodeSeconde << endl;
	}
}

/**
 *�������ҵ������·���Ƿ����ȷ����·���γɻ�·
 *@param graph ͼ���ڽӾ���ȷ����·��Ϊ-2��
 *@param nodeFirst ���ҵ�·����һ��
 *@param nodeSecond ���ҵ�·������һ��
*/
bool findCircle(vector<vector<int>> &graph, int nodeFirst, int nodeSecond) {
	queue<int> notExploration;
	set<int> discovered;
	int start;
	discovered.insert(nodeFirst);
	notExploration.push(nodeFirst);
	while (!notExploration.empty()) {
		start = notExploration.front();
		notExploration.pop();
		for (int j = 0; j < graph[start].size(); j++) {
			if (graph[start][j] == -1) {
				if (j == nodeSecond) {
					return true;
				}
				if (discovered.count(j) == 0) {
					notExploration.push(j);
					discovered.insert(j);
				}
			}
				
		}
	}
	return false;
}

/**
 *��³˹�����㷨������С������
 *@param graph ͼ���ڽӾ���
*/
void kruskal(vector<vector<int>> graph) {
	set<int> discovered;
	vector<struct side> sides;
	int minSide, minNodeX, minNodeY;

	while (sides.size() < graph.size() - 1) {
		minSide = INT_MAX;
		for (int i = 0; i < graph.size(); i++) {
			for (int j = 0; j < graph.size(); j++) {
				if ((graph[i][j] != -1) && (graph[i][j] < minSide)) {
					minSide = graph[i][j];
					minNodeX = i;
					minNodeY = j;
				}//if
			}//for
		}//for
		if (discovered.count(minNodeX) == 0 && discovered.count(minNodeY) == 0) {
			struct side sideTemp;
			sideTemp.nodeFirst = minNodeX;
			sideTemp.nodeSeconde = minNodeY;
			sides.push_back(sideTemp);
			discovered.insert(minNodeX);
			discovered.insert(minNodeY);
			graph[minNodeX][minNodeY] = -1;
			graph[minNodeY][minNodeX] = -1;
		} else if ((discovered.count(minNodeX) == 0 && discovered.count(minNodeY) != 0)
			|| (discovered.count(minNodeX) != 0 && discovered.count(minNodeY) == 0)) {
			struct side sideTemp;
			sideTemp.nodeFirst = minNodeX;
			sideTemp.nodeSeconde = minNodeY;
			sides.push_back(sideTemp);
			graph[minNodeX][minNodeY] = -1;
			graph[minNodeY][minNodeX] = -1;
			discovered.insert(minNodeX);
			discovered.insert(minNodeY);
		} else {
			if (!findCircle(graph, minNodeX, minNodeY)) {
				struct side sideTemp;
				sideTemp.nodeFirst = minNodeX;
				sideTemp.nodeSeconde = minNodeY;
				sides.push_back(sideTemp);
				graph[minNodeX][minNodeY] = -1;
				graph[minNodeY][minNodeX] = -1;
			} else {
				graph[minNodeX][minNodeY] = INT_MAX;
				graph[minNodeY][minNodeX] = INT_MAX;
			}
		}//if
	}//while

	cout << "��³˹�����㷨�õ�����С��������" << endl;
	vector<struct side>::iterator it = sides.begin();
	for (; it != sides.end(); it++) {
		cout << "from " << (*it).nodeFirst << " to " << (*it).nodeSeconde << endl;
	}
}

void main() {
	vector<vector<int>> graph({
		{ INT_MAX, 10, 21, INT_MAX, 8, INT_MAX },
		{ 10, INT_MAX, 18, 5, INT_MAX, 6 },
		{ 21, 18, INT_MAX, INT_MAX, 25, 19 },
		{ INT_MAX, 5, INT_MAX, INT_MAX, INT_MAX, 7 },
		{ 8, INT_MAX, 25, INT_MAX, INT_MAX, 33 },
		{ INT_MAX, 6, 19, 7, 33, INT_MAX }
	});
	kruskal(graph);
	prim(graph, 1);
	system("pause");
}