#include <iostream>
using namespace std;

char board[10000][10000];
int N;

void draw(int num, int x, int y, int type) {
	if (num == 1) {
		if (type == 1) {
			board[y][x] = '*';
		}
		else {
			board[y][x] = ' ';
		}
	}
	else {
		int leng = num / 3;
		for (int j = y; j < y + num; j += leng) {
			for (int i = x; i < x + num; i += leng) {
				if (i == x + leng && j == y + leng) {
					draw(leng, i, j, 0);
				}
				else {
					draw(leng, i, j, type);
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	draw(N, 0, 0, 1);
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			cout << board[j][i];
		}
		cout << "\n";
	}
}