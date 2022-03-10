#include <iostream>
using namespace std;

#define SIZE 100001

int parent[SIZE];
int cnt = 0;
int check = 1;

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
		int tmp = roota;
		roota = rootb;
		rootb = tmp;
	}
	parent[rootb] = roota;
	return 1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int G, P, g;
	cin >> G;
	cin >> P;
	for (int i = 0; i <= G; i++) {
		parent[i] = -1;
	}
	for (int i = 0; i < P; i++) {
		cin >> g;
		if (check) {
			int rootg = find(g);
			if (!rootg) {
				check = 0;
				continue;
			}
			else {
				Union(rootg - 1, rootg);
				cnt++;
			}
		}
	}
	cout << cnt << "\n";
}