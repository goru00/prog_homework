#include<iostream>
#include<string>
#include<queue>
#include<stack>
using namespace std;
struct Edge
{
	int begin;
	int end;
};
int main()
{
	setlocale(0, "");
	queue<int> queue;
	int mass[8][8] = {
		{0, 1, 1, 1, 1, 1, 0, 0},
		{0, 0, 1, 0, 0, 1, 1, 0},
		{0, 0, 0, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 0, 1},
		{0, 0, 0, 0, 0, 1, 1, 0},
		{0, 0, 0, 0, 0, 0, 1, 1},
		{0, 0, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0}
	};
	int nodes[8];
	for (int i = 0; i < 8; i++) nodes[i] = 0;
	int req = 7;
	Edge obj;
	stack<Edge> edges;
	queue.push(0);
	while (!queue.empty())
	{
		int node = queue.front();
		queue.pop();
		nodes[node] = 2;
		for (int i = 0; i < 8; i++)
		{
			if (mass[node][i] == 1 && nodes[i] == 0) {
				queue.push(i);
				nodes[i] = 1;
				obj.begin = node;
				obj.end = i;
				edges.push(obj);
				if (node == req) break;
			}
		}
		cout << node + 1 << endl;
	}
	cout << "Путь до вершины: " << req + 1 << endl;
	cout << req + 1;
	while (!edges.empty())
	{
		obj = edges.top();
		edges.pop();
		if (obj.end == req) {
			req = obj.begin;
			cout << " <- " << req + 1;
		}
	}
	cout << endl;
	return 0;
}