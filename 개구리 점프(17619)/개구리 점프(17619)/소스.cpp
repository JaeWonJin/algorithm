#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

#define SIZE 100001

int N, Q;
int parent[SIZE];
vector<tuple<int, int, int>> logs;
int root = 1;
int root_idx = 0;

int find(int curr) {
	if (parent[curr] < 0) return curr;
	parent[curr] = find(parent[curr]);
	return parent[curr];
}

void Union(int num_idx) {
	int num = get<2>(logs[num_idx]);
	int root = get<2>(logs[root_idx]);
	if (num!=root && get<0>(logs[root_idx]) <= get<0>(logs[num_idx]) && get<0>(logs[num_idx]) <= get<1>(logs[root_idx])) {
		int num_root = find(num);
		int root_root = find(root);
		if (root == num_root) return;
		if (get<1>(logs[root_idx]) < get<1>(logs[num_idx])) {
			get<1>(logs[root_idx]) = get<1>(logs[num_idx]);
		}
		parent[num_root] = root;
	}
	else {
		root_idx = num_idx;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> Q;

	for (int i = 1; i <= N; i++) {
		parent[i] = -1;
		int x1, x2, y;
		cin >> x1 >> x2 >> y;
		logs.push_back(make_tuple(x1, x2, i));
	}
	sort(logs.begin(), logs.end());
	root = get<2>(logs[0]);
	for (int i = 0; i < N; i++) {
		Union(i);
	}

	for (int i = 0; i < Q; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		if (find(num1) == find(num2)) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
	}
}