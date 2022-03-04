#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 100000000
#define SIZE 20001

int V, E;
int u, v, w;
int start;
vector<pair<int,int>> adj[SIZE];
int dis[SIZE] = { 0, };
int visited[SIZE] = { 0, };

int main(void) {
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> H;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E;
	cin >> start;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(w, v));
	}
	H.push(make_pair(0, start));
	for (int i = 1; i <= V; i++) {
		dis[i] = INF;
	}
	while (!H.empty()) {
		pair<int, int> tmp = H.top();
		H.pop();
		int cur = tmp.second;
		int distance = tmp.first;
		if (visited[cur] || distance > dis[cur]) continue;
		visited[cur] = 1;
		dis[cur] = distance;

		for (int i = 0; i < adj[cur].size(); i++) {
			pair<int, int> nxttmp = adj[cur][i];
			int next = nxttmp.second;
			int nxt_dis = nxttmp.first;
			if (dis[next] > dis[cur] + nxt_dis) {
				dis[next] = dis[cur] + nxt_dis;
				H.push(make_pair(dis[next], next));
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dis[i] == INF) cout << "INF\n";
		else cout << dis[i] << "\n";
	}
}