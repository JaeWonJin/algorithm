#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define SIZE 100001

int board[21][21];
queue<pair<int, int>> Q;
queue<pair<int, int>> Q2;
int dx[4] = { 0,-1,1,0 };
int dy[4] = { -1,0,0,1 };
int tme = 0;
int N;
int baby_size = 2;
int ex = 0;
int fish_num = 0;
int jump = 0;
int ans = 0;

void displayBoard(void) {
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			cout << board[j][i] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void BFS(void) {
	while (!Q.empty() && fish_num) {
		int rep = Q.size();
		tme++;
		//displayBoard();
		for (int i = 0; i < rep; i++) {
			pair<int, int> t = Q.front();
			Q2.push(t);
			Q.pop();
			int x = t.first;
			int y = t.second;
			//cout << "(" << x << ", " << y << ") ";
			for (int k = 0; k < 4; k++) {
				int newx = dx[k] + x;
				int newy = dy[k] + y;
				if (newx >= 0 && newx < N && newy >= 0 && newy < N) {
					if (board[newy][newx]>0 && board[newy][newx]<9 && baby_size > board[newy][newx]) {
						ex++;
						fish_num--;
						if (ex >= baby_size) {
							ex = 0;
							baby_size += 1;
						}
						while (!Q.empty()) {
							pair<int, int>tmp = Q.front();
							board[tmp.second][tmp.first] -= 9;
							Q.pop();
						}
						while (!Q2.empty()) {
							pair<int, int>tmp = Q2.front();
							board[tmp.second][tmp.first] -= 9;
							Q2.pop();
						}
						board[newy][newx] = 9;
						if (!fish_num) {
							ans+=tme;
							return;
						}
						Q.push(make_pair(newx, newy));
						ans += tme;
						tme = 0;
						cout << baby_size <<":"<<ex<<" "<< ans << "\n";
						displayBoard();
						jump = 1;
						break;
					}
					else if (baby_size == board[newy][newx] || !board[newy][newx]) {
						board[newy][newx] += 9;
						Q.push(make_pair(newx, newy));
					}
				}
			}
			if (jump) {
				jump = 0;
				break;
			}
		}
	}
}

int main(void) {
	cin >> N;
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			cin >> board[j][i];
			if (board[j][i] == 9) {
				Q.push(make_pair(i, j));
			}
			else if (board[j][i] > 0) {
				fish_num++;
			}
		}
	}
	BFS();
	displayBoard();
	cout << ans << "\n";

}