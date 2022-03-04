#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define SIZE 801
#define INF 200000001

int N, E;
int a, b, c;
int start = 1;
int v1, v2;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
vector<pair<int, int>> adj[SIZE];
int dist[SIZE][SIZE];
int visited[SIZE];

int min(int x, int y) {
	if (x < y) return x;
	return y;
}

void dijkstra(int start) {
	minH.push(make_pair(0, start));
	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
	}
	while (!minH.empty()) {
		pair<int, int> tmp = minH.top();
		int cur = tmp.second;
		int cur_distance = tmp.first;
		minH.pop();
		if (visited[cur] || cur_distance > dist[start][cur]) continue;
		dist[start][cur] = cur_distance;
		visited[cur] = 1;

		for (int i = 0; i < adj[cur].size(); i++) {
			pair<int, int> nxttmp = adj[cur][i];
			int next = nxttmp.second;
			int next_distance = nxttmp.first;
			if (dist[start][next] > dist[start][cur] + next_distance) {
				dist[start][next] = dist[start][cur] + next_distance;
				minH.push(make_pair(dist[start][next], next));
			}
		}
	}
}

int main(void) {
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(c, b));
		adj[b].push_back(make_pair(c, a));
	}
	cin >> v1 >> v2;
	for (int i = 1; i <= N; i++) {
		dist[start][i] = INF;
		dist[v1][i] = INF;
		dist[v2][i] = INF;
	}
	dijkstra(start);
	dijkstra(v1);
	dijkstra(v2);
	int ans = dist[start][v1] + dist[v1][v2] + dist[v2][N];
	ans = min(ans, dist[start][v2] + dist[v2][v1] + dist[v1][N]);
	if (ans >= INF) ans = -1;
	cout << ans << "\n";
}