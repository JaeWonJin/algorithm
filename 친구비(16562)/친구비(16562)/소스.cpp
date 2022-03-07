#include <iostream>
using namespace std;

#define SIZE 10001

long long int N, M, k;
int cost[SIZE];
int parent[SIZE];

int find(int curr) {
	if (parent[curr] < 0) return curr;
	parent[curr] = find(parent[curr]);
	return parent[curr];
}

void Union(int a, int b) {
	int roota = find(a);
	int rootb = find(b);
	if (roota == rootb) return;
	if (cost[roota] > cost[rootb]) {
		parent[roota] = rootb;
	}
	else {
		parent[rootb] = roota;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> k;
	
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		parent[i] = -1;
	}
	fill(parent, parent + N + 1, -1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}
	long long int ans=0;
	for (int i = 1; i <= N; i++) {
		if (parent[i]==-1) {
			ans += cost[i];
		}
	}
	if (ans<=k) {
		cout << ans << "\n";
	}
	else {
		cout << "Oh no\n";
	}
}