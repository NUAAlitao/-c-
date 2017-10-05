#include<iostream>
#include<queue>
#include<vector>
#include<set>
using namespace std;

/**
 *查找当前节点所能到达的节点中距离最短的节点和距离值
 *@param distanceTemp 当前节点所能到达的节点和距离
 *@param discovered 已经计算的节点
 *@param node 存放查找到的节点
 *param distance 存放查找到的距离
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
 *根据查找到的最小距离节点更新所能到达的各点距离信息
 *param graph 图的邻接矩阵
 *param distanceTemp 当前节点所能到达的节点和距离
 *param discovered 已经计算的节点
 *param route 从开始节点到达各个节点的路径
 *param node 查找到的当前距离最短的节点
 *param distance 查找到的当前的最短距离
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
 *求一节点到各个节点的最短路径
 *@param graph 图的邻接矩阵
 *@param start 开始节点
*/
void dijkstra(vector<vector<int>>& graph, int start) {
	set<int> discovered;             //被发现并计算的节点
	vector<queue<int>> route(graph.size(), queue<int>());			//从开始节点到各个节点的路径
	vector<int> distance(graph.size());			//从开始节点到各个节点的距离
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

	cout << "节点 " << start << " 到各个节点的最短路径：" << endl;
	for (int i = 0; i < graph.size(); i++) {
		if (i == start) {
			continue;
		}
		cout << "路径：";
		while (!route[i].empty()) {
			cout << route[i].front() << ' ';
			route[i].pop();
		}
		cout << "  最短路径距离：" << distance[i] << endl;
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