#include <iostream>
using namespace std;

char board[4000][8000];
int N;

void draw(int num, int x, int y) {
	if (num == 3) {
		board[y][x] = '*';
		board[y + 1][x - 1] = '*';
		board[y + 1][x + 1] = '*';
		for (int i = x - 2; i <= x + 2; i++) {
			board[y + 2][i] = '*';
		}
	}
	else {
		draw(num / 2, x, y);
		draw(num / 2, x + num / 2, y + num / 2);
		draw(num / 2, x - num / 2, y + num / 2);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < 2*N-1; i++) {
			board[j][i] = ' ';
		}
	}
	draw(N, N - 1, 0);
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < 2 * N - 1; i++) {
			cout << board[j][i];
		}
		cout << "\n";
	}
	return 0;
}