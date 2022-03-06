#include <iostream>
using namespace std;

#define SIZE 201

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
	if (roota > rootb) {
		int tmp = roota;
		roota = rootb;
		rootb = tmp;
	}
	parent[rootb] = roota;
}

int main(void) {
	int N, M;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		parent[i] = -1;
	}
	cin >> M;
	int islinked = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> islinked;
			if (islinked) Union(i, j);
		}
	}
	int num;
	int ans=1;
	cin >> num;
	int numroot = find(num);
	for (int i = 0; i < M - 1; i++) {
		cin >> num;
		if (numroot != find(num)) {
			ans = 0;
		}
	}
	if (ans) cout << "YES\n";
	else cout << "NO\n";
}