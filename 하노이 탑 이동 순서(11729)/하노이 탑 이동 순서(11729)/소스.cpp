#include <iostream>
#include <vector>
using namespace std;

int K = 0;
vector<pair<int, int>> ans;

void hanoi(int num, int a, int b, int c) {
	if (num == 1) {
		K++;
		ans.push_back(make_pair(a, c));
	}
	else {
		hanoi(num - 1, a, c, b);
		hanoi(1, a, b, c);
		hanoi(num - 1, b, a, c);
	}
}

int main(void) {
	int N;
	cin >> N;
	hanoi(N, 1, 2, 3);
	cout << K;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
}