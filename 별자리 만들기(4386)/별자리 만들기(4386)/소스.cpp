#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

vector<tuple<int, double, double>> points;
vector<tuple<double, int, int>> edges;
int N;
int parent[101];

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

double distance(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		parent[i] = -1;
		double x, y;
		cin >> x >> y;
		points.push_back(make_tuple(i, x, y));
	}
	for (int i = 0; i < N; i++) {
		tuple<int, double, double> point = points.back();
		points.pop_back();
		for (int j = 0; j < points.size(); j++) {
			tuple<int, double, double> adj_point = points[j];
			double dis = distance(get<1>(point), get<2>(point), get<1>(adj_point), get<2>(adj_point));
			edges.push_back(make_tuple(dis, get<0>(point), get<0>(adj_point)));
		}
	}
	sort(edges.begin(), edges.end());
	double ans = 0;
	for (int i = 0; i < edges.size(); i++) {
		int v1 = get<1>(edges[i]);
		int v2 = get<2>(edges[i]);
		if (Union(v1, v2)) {
			ans += get<0>(edges[i]);
		}
	}
	cout << ans << "\n";
}