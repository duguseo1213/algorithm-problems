#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string dp[51][51][51][3][3]; //a,b,c // 뒤쪽 2칸에 a,b,c 인지 뒤쪽 1칸에 a,b,c인지

string temp;

int main() {

    cin >> temp;

    dp[1][0][0][0][0] = "A";
    dp[0][1][0][0][1] = "B";
    dp[0][0][1][0][2] = "C";

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            for (int k = 0; k < 50; k++) {

                if (i + j + k > 50) continue;

                for (int l = 0; l < 3; l++) {

                    for (int m = 0; m < 3; m++) {
                        if (dp[i][j][k][l][m] == "") continue;
                        //A를 붙이는 경우

                        if (dp[i + 1][j][k][m][0] == "") {
                            dp[i + 1][j][k][m][0] = dp[i][j][k][l][m] + "A";
                        }

                        if (dp[i][j + 1][k][m][1] == "" && m!=1) {
                           
                            dp[i][j + 1][k][m][1] = dp[i][j][k][l][m] + "B";                          

                        }

                        if (dp[i][j][k + 1][m][2] == "" && m!=2 && l!=2) {
                          
                            dp[i][j][k+1][m][2] = dp[i][j][k][l][m] + "C";

                        }


                    }


                }
                

            }
        }
    }

    int a = 0;
    int b = 0;
    int c = 0;

    

    for (int i = 0; i < temp.size(); i++) {

        if (temp[i] == 'A') {

            a++;
        }
        if (temp[i] == 'B') {

            b++;
        }
        if (temp[i] == 'C') {

            c++;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (dp[a][b][c][i][j] != "") {
                cout << dp[a][b][c][i][j];
                return 0;
            }

        }
    }

    cout << -1;

}