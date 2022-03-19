#include <iostream>
#include <vector>
using namespace std;

#define INF 60000001

int N, M;
long long dist[501];
vector<vector<pair<int, int>>> adj;


int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		adj.push_back({});
		dist[i] = INF;
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a - 1].push_back(make_pair(b - 1, c));
	}
	dist[0] = 0;
	for (int rep = 0; rep < N - 1; rep++) {
		for (int i = 0; i < N; i++) {
			if (dist[i] >= INF) continue;
			for (int j = 0; j < adj[i].size(); j++) {
				pair<int, int> nexttmp = adj[i][j];
				int next = nexttmp.first;
				int w = nexttmp.second;
				if (dist[next] > dist[i] + w) {
					dist[next] = dist[i] + w;
				}
			}
		}
	}
	int check = 1;
	int jump = 0;
	for (int i = 0; i < N; i++) {
		if (dist[i] >= INF) continue;
		for (int j = 0; j < adj[i].size(); j++) {
			pair<int, int> nexttmp = adj[i][j];
			int next = nexttmp.first;
			int w = nexttmp.second;
			if (dist[next] > dist[i] + w) {
				check = 0;
				jump = 1;
				break;
			}
		}
		if (jump) break;
	}
	if (check) {
		for (int i = 1; i < N; i++) {
			if (dist[i] == INF) {
				cout << -1 << "\n";
			}
			else {
				cout << dist[i] << "\n";
			}
		}
	}
	else {
		cout << -1 << "\n";
	}
	return 0;
}
