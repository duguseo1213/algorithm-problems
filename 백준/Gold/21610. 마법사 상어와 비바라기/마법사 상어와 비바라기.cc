#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int N,M;

int arr[100][100];

int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
int dx[8] = { -1,-1,0,1,1,1,0,-1 };

int ddy[4] = { 1,1,-1,-1 };
int ddx[4] = { -1,1,-1,1 };


int cloud[100][100];
int cloud2[100][100];
int d, s;

void move(int cnt) {

    
    if (cnt == 0) {
        cloud[N - 1][0] = 1;
        cloud[N - 1][1] = 1;

        cloud[N - 2][0] = 1;
        cloud[N - 2][1] = 1;

    }
    else {

        
    }




    memset(cloud2, 0, sizeof(cloud2));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            int ny=i;
            int nx=j;
            for (int k = 0; k < s; k++) {

                ny = ny + dy[d];
                nx = nx + dx[d];

                if (ny > N - 1) {
                    ny = 0;
                }
                if (ny < 0) {
                    ny = N - 1;
                }
                if (nx > N - 1) {
                    nx = 0;
                }
                if (nx < 0) {
                    nx = N - 1;
                }

            }

            cloud2[ny][nx] = cloud[i][j];


        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            if (cloud2[i][j] == 1) {
                arr[i][j]++;



            }

            


        }
     
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            if (cloud2[i][j] == 1) {
                

                for (int k = 0; k < 4; k++) {

                    int ny = i + ddy[k];
                    int nx = j + ddx[k];

                    if (ny<0 || nx<0 || ny>N - 1 || nx>N - 1) continue;

                    if (arr[ny][nx] > 0) {
                        arr[i][j]++;
                    }

                }


            }




        }

    }

    memset(cloud, 0, sizeof(cloud));


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            if (arr[i][j] >= 2 && cloud2[i][j] != 1) {
                arr[i][j] -= 2;
                cloud[i][j] = 1;
            }
        }
    }

   
    cnt++;

   

}

int main() {
    
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < M; i++) {
        
        scanf("%d %d", &d, &s);
        d--;
        move(i);
    }

    int answer = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            answer += arr[i][j];
        }
    }

    printf("%d", answer);

}