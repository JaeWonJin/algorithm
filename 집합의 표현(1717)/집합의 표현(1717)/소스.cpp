#include <iostream>


using namespace std;

int parent[1000001];

int find(int curr) {
	if (parent[curr] == -1) return curr;
	parent[curr] = find(parent[curr]);
	return parent[curr];
}

void Union(int a, int b) {
	int root1 = find(a);
	int root2 = find(b);

	if (root1 == root2) {
		return;
	}

	if (root2 > root1) {
		int tmp = root2;
		root2 = root1;
		root1 = tmp;
	}

	parent[root1] = root2;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	int order, a, b;
	for (int i = 0; i <= N; i++) {
		parent[i] = -1;
	}
	for (int i = 0; i < M; i++) {
		cin >> order >> a >> b;
		if (order == 0) {
			Union(a, b);
		}
		else {
			if (find(a) == find(b)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}

	}
}