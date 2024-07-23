#define P
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>

using namespace std;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { -1,0,1,0 };

vector<int> vec;

int gu[4];

int N, M;
int arr[50][50];
vector<int> num[4];
//9 17 25 33
// 서쪽 0, 9, 26, 51
// 남쪽 2 13 32
// 동쪽 4 17 
// 북쪽 6 21 44 
//vector 만들어서 삽입 제거.
int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int temp = 9;
	int good = 0;
	for (int i = 0; i < 200; i++) {
		num[0].push_back(good);
		good += temp;
		temp += 8;
	}
	temp = 11;
	good = 2;
	for (int i = 0; i < 200; i++) {
		num[1].push_back(good);
		good += temp;
		temp += 8;
	}
	temp = 13;
	good = 4;
	for (int i = 0; i < 200; i++) {
		num[2].push_back(good);
		good += temp;
		temp += 8;
	}
	temp = 15;
	good = 6;
	for (int i = 0; i < 200; i++) {
		num[3].push_back(good);
		good += temp;
		temp += 8;
	}


	int sy = N / 2;
	int sx = N / 2;
	int y = N / 2;
	int x = N / 2;
	int ny;
	int nx;

	int d = 0;
	int state = 0;
	int cnt = 0;
	int range = 1;
	while (1) {

		for (int i = 0; i < range; i++) {
			y = y + dy[d];
			x = x + dx[d];

			if (y<0 || x<0 || y>N - 1 || x>N - 1 || arr[y][x] == 0) {
				state = 1;
				break;
			};
			vec.push_back(arr[y][x]);

		}
		d = (d + 1) % 4;
		cnt++;
		if (cnt == 2) {
			cnt = 0;
			range++;
		}
		if (state == 1) {
			break;
		}
	}

	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);

		int dir = -1;
		if (a == 1) {
			dir = 3;
		}
		else if (a == 2) {
			dir = 1;
		}
		else if (a == 3) {
			dir = 0;
		}
		else {
			dir = 2;
		}

		for (int j = 0; j < b; j++) {

			int temp = num[dir][j] - j;
			if (vec.size() <= temp) {
				break;
			}
			//if (vec.size() == 0) break;
			vec.erase(vec.begin() + temp);
		}

		for (int i = 0; i < vec.size(); i++) {
			P("%d ", vec[i]);
		}

		P("\n");


		while (1) {
			int flag = 0;
			vector<int> newvec;
			int temp = 1;
			for (int i = 0; i < vec.size(); i++) {

				if (newvec.size() == 0) {
					newvec.push_back(vec[i]);
					temp = 1;
					continue;
				}


				if (vec[i] == newvec.back()) {
					newvec.push_back(vec[i]);
					temp++;
				}
				else {
					if (temp >= 4) {
						flag = 1;

						gu[newvec.back()] = gu[newvec.back()] + temp;

						for (int j = 0; j < temp; j++) {
							newvec.pop_back();
						}



					}
					temp = 1;
					newvec.push_back(vec[i]);
				}
			}

			if (temp >= 4) {
				flag = 1;

				gu[newvec.back()] = gu[newvec.back()] + temp;

				for (int j = 0; j < temp; j++) {
					newvec.pop_back();
				}



			}



			vec = newvec;

			for (int i = 0; i < vec.size(); i++) {
				P("%d ", vec[i]);
			}

			P("\n");
			if (flag == 0) break;
		}

		vector<int> newnewvec;

		int temp = 1;
		int numnum = -1;


		for (int i = 0; i < vec.size(); i++) {

			if (i == 0) {
				numnum = vec[i];
				temp = 1;
				continue;
			}

			if (vec[i] == numnum) {
				temp++;
			}
			else {

				newnewvec.push_back(temp);
				newnewvec.push_back(numnum);
				temp = 1;
				numnum = vec[i];

			}

		}

		if (vec.size() > 0)
		{

			newnewvec.push_back(temp);
			newnewvec.push_back(numnum);
		}
		vec = newnewvec;

		for (int i = 0; i < vec.size(); i++) {
			P("%d ", vec[i]);
		}

		P("\n");

		while (1) {
			if (vec.size() <= N * N - 1) break;
			vec.pop_back();
		}


	}

	printf("%d", gu[1] + gu[2] * 2 + gu[3] * 3);

}
