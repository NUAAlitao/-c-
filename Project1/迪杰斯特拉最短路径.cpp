#include<iostream>
#include<queue>
#include<vector>
#include<set>
using namespace std;

/**
 *���ҵ�ǰ�ڵ����ܵ���Ľڵ��о�����̵Ľڵ�;���ֵ
 *@param distanceTemp ��ǰ�ڵ����ܵ���Ľڵ�;���
 *@param discovered �Ѿ�����Ľڵ�
 *@param node ��Ų��ҵ��Ľڵ�
 *param distance ��Ų��ҵ��ľ���
*/
void findMinDistance(vector<int> &distanceTemp, set<int>& discovered, int &node, int &distance) {
	distance = distanceTemp[0];
	node = 0;
	for (int i = 1; i < distanceTemp.size(); i++) {
		if (discovered.count(i)==0 && (distanceTemp[i] != -1) && (distanceTemp[i] < distance || distance == -1)) {
			node = i;
			distance = distanceTemp[i];
		}
	}
}

/**
 *���ݲ��ҵ�����С����ڵ�������ܵ���ĸ��������Ϣ
 *param graph ͼ���ڽӾ���
 *param distanceTemp ��ǰ�ڵ����ܵ���Ľڵ�;���
 *param discovered �Ѿ�����Ľڵ�
 *param route �ӿ�ʼ�ڵ㵽������ڵ��·��
 *param node ���ҵ��ĵ�ǰ������̵Ľڵ�
 *param distance ���ҵ��ĵ�ǰ����̾���
*/
void calculateNextDistance(vector<vector<int>>& graph, vector<int>& distanceTemp, set<int>& discovered, vector<queue<int>>& route,
							int node, int distance) {
	vector<int> nodeDistance(graph[node]);
	for (int i = 0; i < graph[node].size(); i++) {
		if ((discovered.count(i) == 0) && (nodeDistance[i] != -1 && (nodeDistance[i] + distance < distanceTemp[i] || distanceTemp[i]==-1))) {
			distanceTemp[i] = nodeDistance[i] + distance;
			route[i].push(node);
		}
	}
}
/**
 *��һ�ڵ㵽�����ڵ�����·��
 *@param graph ͼ���ڽӾ���
 *@param start ��ʼ�ڵ�
*/
void dijkstra(vector<vector<int>>& graph, int start) {
	set<int> discovered;             //�����ֲ�����Ľڵ�
	vector<queue<int>> route(graph.size(), queue<int>());			//�ӿ�ʼ�ڵ㵽�����ڵ��·��
	vector<int> distance(graph.size());			//�ӿ�ʼ�ڵ㵽�����ڵ�ľ���
	vector<int> distanceTemp(graph[start]);
	int node, minDistance;

	for (int i = 0; i < graph.size(); i++) {
		route[i].push(start);
	}
	discovered.insert(start);
	while (discovered.size() < graph.size()) {
		findMinDistance(distanceTemp, discovered,node, minDistance);
		distance[node] = minDistance;
		route[node].push(node);
		discovered.insert(node);
		calculateNextDistance(graph, distanceTemp, discovered, route, node, minDistance);
	}

	cout << "�ڵ� " << start << " �������ڵ�����·����" << endl;
	for (int i = 0; i < graph.size(); i++) {
		if (i == start) {
			continue;
		}
		cout << "·����";
		while (!route[i].empty()) {
			cout << route[i].front() << ' ';
			route[i].pop();
		}
		cout << "  ���·�����룺" << distance[i] << endl;
	}
}

void main() {
	vector<vector<int>> graph( {   { -1, 3, 5, 2, -1, -1 },
						{ -1, -1, -1, 2, -1, 7 },
						{ -1, 4, -1, -1, -1, -1 },
						{ -1, -1, 1, -1, 6, 2 },
						{-1,-1,-1,-1,-1,1},
						{-1,-1,-1,-1,2,-1}
	});
	dijkstra(graph, 2);
	system("pause");
}