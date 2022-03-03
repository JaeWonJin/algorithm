#include <iostream>
using namespace std;

#define INF 10000

int min(int x, int y) {
	if (x < y) return x;
	return y;
}

void printboard(int board[251][251], int N) {
	cout << "\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j] == INF) {
				cout << "* ";
			}
			else {
				cout << board[i][j] << " ";
			}
		}
		cout << "\n";
	}
}

void floyd(int board[251][251], int N) {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int board[251][251];
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				board[i][j] = 0;
			}
			else {
				board[i][j] = INF;
			}
		}
	}
	int u, v, b;
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> b;
		if (b) {
			board[u][v] = 0;
			board[v][u] = 0;
		}
		else {
			board[u][v] = 0;
			board[v][u] = 1;
		}
	}
	floyd(board, N);

	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> u >> b;
		cout << board[u][b] << "\n";
	}
}