#define P printf
#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
using namespace std;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int N, M;

vector<string> vec;


int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {

		string temp;
		cin >> temp;

		vec.push_back(temp);

	}

	int state = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if (vec[i][j] == '.') {
				vec[i][j] = 'D';
			}


			if (vec[i][j] == 'W') {

				for (int k = 0; k < 4; k++) {

					int ny = dy[k] + i;
					int nx = dx[k] + j;

					if (ny<0 || nx<0 || ny>N - 1 || nx>M - 1) continue;

					if (vec[ny][nx] == 'S') {
						state = 0;
					}

				}


			}

		}
	}




	cout << state << "\n";
	if (state == 1) {


		for (int i = 0; i < N; i++) {
			cout << vec[i] << "\n";
		}
	}
	


}