#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int N, M;

vector<string> vec;

int dp[1001][1001][3]; //가로 세로 대각선
int answer = -1;

int main(){

    scanf("%d %d", &N, &M);
    string temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        vec.push_back(temp);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j == 0) {
                if (vec[i][j] == '1') dp[i][j][0] = 1;
            }
            else {
                if(vec[i][j]=='1') dp[i][j][0] = dp[i][j-1][0]+1;
            }

            if (i == 0) {
                if (vec[i][j] == '1') dp[i][j][1] = 1;
            }
            else {
                if (vec[i][j] == '1') dp[i][j][1] = dp[i-1][j][1] + 1;
            }
            
            if (vec[i][j] == '1') dp[i][j][2] = 1;
            
           
        }
    }
    /*
    for (int k = 0; k < 3; k++) {


        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                printf("%d ", dp[i][j][k]);

            }
            printf("\n");
        }
        printf("\n");
    }*/

    


    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            
            dp[i][j][2] = min({ dp[i - 1][j - 1][2]+1, dp[i][j][0], dp[i][j][1] });

            

                
        }
        //printf("\n");
    }
    //printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            //dp[i][j][2] = min(dp[i - 1][j - 1][2], dp[i][j][0], dp[i][j][1]);

            answer = max(answer, dp[i][j][2]);

           // printf("%d ", dp[i][j][2]);


        }
        //printf("\n");
    }

    printf("%d", answer*answer);


}