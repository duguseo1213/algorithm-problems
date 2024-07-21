#define P printf
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <ctime>
#include <set>
using namespace std;

//int arr[1001][1001];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int N, M;
set<int> se;

int visit[1001][1001];

int answer[1001][1001];

int cnt;

int id;


int dat[1000001];

vector<string> arr;
queue<pair<int, int>> q;
void bfs(int y,int x,int id) {
	cnt = 1;
	q.push({ y,x });
	while (!q.empty())
	{
		y = q.front().first;
		x = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {

			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny<0 || nx<0 || ny> N - 1 || nx>M - 1) continue;

			if (visit[ny][nx] == 0 && arr[ny][nx]=='0') {
				visit[ny][nx] = id;
				cnt++;
				q.push({ ny,nx });

			}


		}
	}
	//cout << cnt;
	dat[id] = cnt;

}

int main() {


	clock_t start, finish;

	scanf("%d %d", &N, &M);
	string temp;

	start = clock();
	
	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr.push_back(temp);
		
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//if (arr[i][j] == '1') answer[i][j]++;


			if (arr[i][j] == '0' && visit[i][j] == 0) {

				id++;
				visit[i][j] = id;
				bfs(i, j, id);

			}
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			
			if (arr[i][j] == '1') {
				se.clear();
				answer[i][j]++;
				for (int k = 0; k < 4; k++) {

					int ny = i + dy[k];
					int nx = j + dx[k];

					if (ny<0 || nx<0 || ny> N - 1 || nx>M - 1) continue;
					se.insert(visit[ny][nx]);
					//answer[i][j] = answer[i][j] + dat[visit[ny][nx]];

					//printf("%d ", visit[ny][nx]);

				}

				for (auto k = se.begin(); k != se.end(); k++) {

					answer[i][j] += dat[*k];

					answer[i][j] = answer[i][j] % 10;
				}



			}


		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << answer[i][j];
		}
		cout << "\n";
	}
	
	

	finish = clock();
	
}