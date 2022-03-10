#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

vector<tuple<int, int, int>> edges;
int V, E;
int parent[10001];

int find(int curr) {
	if (parent[curr] < 0) return curr;
	parent[curr] = find(parent[curr]);
	return parent[curr];
}

int Union(int a, int b) {
	int roota = find(a);
	int rootb = find(b);
	if (roota == rootb) return 0;
	if (roota > rootb) {
		parent[roota] = rootb;
	}
	else {
		parent[rootb] = roota;
	}
	return 1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E;
	for (int i = 1; i <= V; i++) {
		parent[i] = -1;
	}
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back(make_tuple(c, a, b));
	}
	sort(edges.begin(), edges.end());
	int ans = 0;
	for (int i = 0; i < E; i++) {
		int v1 = get<1>(edges[i]);
		int v2 = get<2>(edges[i]);
		if (Union(v1, v2)) {
			ans += get<0>(edges[i]);
		}
	}
	cout << ans << "\n";
}