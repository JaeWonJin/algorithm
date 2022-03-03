#include <iostream>
#include <stdlib.h>
using namespace std;

char board[21][21];
int R, C;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int check['Z' - 'A' + 1] = { 0, };
int ans = 1;
int cnt = 1;

int max(int x, int y) {
	if (x > y) return x;
	return y;
}

void display(void) {
	for (int j = 0; j < R; j++) {
		for (int i = 0; i < C; i++) {
			cout << board[j][i] << " ";
		}
		cout << "\n";
	}
}

void DFS(int x, int y, char ch) {
	for (int k = 0; k < 4; k++) {
		int newx = x + dx[k];
		int newy = y + dy[k];
		if (newx >= 0 && newx < C && newy >= 0 && newy < R) {
			if (board[newy][newx]>='A' && board[newy][newx]<='Z' && !check[board[newy][newx] - 'A']) {
				check[board[newy][newx]-'A'] = 1;
				char newch = board[newy][newx];
				board[newy][newx] = '.';
				cnt++;
				DFS(newx, newy, newch);
			}
		}
	}
	ans = max(ans, cnt);
	//cout << ans << "\n";
	//display();
	check[ch - 'A'] = 0;
	board[y][x] = ch;
	cnt -= 1;
	
	
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	for (int j = 0; j < R; j++) {
		cin >> board[j];
	}
	check[board[0][0]-'A'] = 1;
	board[0][0] = '.';
	DFS(0, 0, board[0][0]);
	cout << ans << "\n";
}