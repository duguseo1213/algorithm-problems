#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int N,K;

string dp[31][31][31][450];


int main() {
    scanf("%d %d", &N, &K);

    dp[0][0][1][0] = 'C';
    dp[0][1][0][0] = 'B';
    dp[1][0][0][0] = 'A';

    int state = 0;



    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            for (int k = 0; k < 30; k++) {

                if (i + j + k > 30) continue;

                for (int l = 0; l < 450; l++) {

                    if (dp[i][j][k][l] == "")continue;

                    if (dp[i + 1][j][k][l + j + k] == "") {
                        dp[i + 1][j][k][l+j+k] = "A" + dp[i][j][k][l];
                    }
                    if (dp[i][j + 1][k][l + k] == "" ) {
                        dp[i][j + 1][k][l+k] = "B" + dp[i][j][k][l];
                    }
                    if (dp[i][j][k+1][l] == "") {
                        dp[i][j][k + 1][l] = "C" + dp[i][j][k][l];
                    }
                    
                    
                    

                }
            }
        }
    }
    string answer = "";
    for (int i = 0; i <= 30; i++) {
        for (int j = 0; j <= 30; j++) {
            for (int k = 0; k <= 30; k++) {

                if (i + j + k > 30) continue;

                if (i + j + k == N && dp[i][j][k][K]!="") {
                    answer = dp[i][j][k][K];
                    goto label;
                }
                
            }
        }
    }



label:

    if (answer == "") cout << -1;
    else cout << answer;

    


}