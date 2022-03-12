#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

char board[51][51];
int N, M;
vector<pair<int, int>> points;
pair<int, int> start;
queue<pair<int, int>> Q1;
queue<pair<int, int>> Q2;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minH;
vector<vector<pair<int, int>>> adj;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int visited[251] = { 0, };

void printBoard(void) {
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			cout << board[j][i];
		}
		cout << "\n";
	}
	cout << "\n";
}

void printadj(void) {
	for (int i = 0; i < adj.size(); i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			cout << i << "->" << adj[i][j].first << " : " << adj[i][j].second << "\n";
		}
	}
}


void BFS(pair<int, int> point, int pointindex) {
	board[point.second][point.first] = '*';
	int leng = 1;
	Q1.push(point);
	Q2.push(point);
	while (!Q1.empty()) {
		//printBoard();
		int rep = Q1.size();
		for (int i = 0; i < rep; i++) {
			pair<int, int> tmp = Q1.front();
			int x = tmp.first;
			int y = tmp.second;
			Q1.pop();
			for (int k = 0; k < 4; k++) {
				int newx = x + dx[k];
				int newy = y + dy[k];
				if (newx >= 0 && newx < N && newy >= 0 && newy < N) {
					if (board[newy][newx] == 'S' || board[newy][newx] == 'K') {
						board[newy][newx] = '*';
						Q2.push(make_pair(newx, newy));
						for (int i = 0; i < points.size(); i++) {
							if (points[i].first == newx && points[i].second == newy) {
								adj[pointindex].push_back(make_pair(i, leng));
							}
						}
					}
					else if (board[newy][newx] == '0') {
						board[newy][newx] = '.';
						Q1.push(make_pair(newx, newy));
						Q2.push(make_pair(newx, newy));
					}
				}
			}
		}
		leng++;
	}
	//printBoard();
	while (!Q2.empty()) {
		pair<int, int> tmp = Q2.front();
		int x = tmp.first;
		int y = tmp.second;
		Q2.pop();
		if (board[y][x] == '.') {
			board[y][x] = '0';
		}
		else if (board[y][x] == '*') {
			board[y][x] = 'K';
		}
	}
}

int main(void) {
	cin >> N >> M;
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			cin >> board[j][i];
			if (board[j][i] == 'K') {
				points.push_back(make_pair(i, j));
			}
			else if (board[j][i] == 'S') {
				start = make_pair(i, j);
			}
		}
	}
	points.push_back(start);
	int last_idx = points.size() - 1;
	for (int i = 0; i < points.size(); i++) {
		adj.push_back({});
	}
	for (int i = 0; i < points.size(); i++) {
		BFS(points[i], i);
	}
	//printadj();
	int linked_vertex_num = 1;
	visited[last_idx] = 1;
	int ans = 0;
	for (int i = 0; i < adj[last_idx].size(); i++) {
		minH.push(make_tuple(adj[last_idx][i].second, last_idx, adj[last_idx][i].first));
	}
	while (!minH.empty()) {
		tuple<int, int, int> tmp = minH.top();
		int dis = get<0>(tmp);
		int v1 = get<1>(tmp);
		int v2 = get<2>(tmp);
		minH.pop();
		if (!visited[v2]) {
			linked_vertex_num += 1;
			visited[v2] = 1;
			ans += dis;
			for (int i = 0; i < adj[v2].size(); i++) {
				minH.push(make_tuple(adj[v2][i].second, v2, adj[v2][i].first));
			}
		}

	}
	if (linked_vertex_num == M + 1) {
		cout << ans << "\n";
	}
	else {
		cout << "-1\n";
	}
}