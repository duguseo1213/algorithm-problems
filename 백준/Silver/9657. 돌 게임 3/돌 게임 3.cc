#include <iostream>
using namespace std;

int dp[1005] = { 0, };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n;
	cin >> n;

	//문제 해결
	/* 마지막에 가져가는 사람이 이긴다.
	* 상근:1  창영:0    괄호 안은 돌 개수
	* dp[i]=1은 i개의 돌이 남았을 때, 
	* 상근이의 차례라면 이긴다는 뜻이다.
	dp[1]=1	(1)
	dp[2]=0 (1 1)
	dp[3]=1 (3)
	dp[4]=1	(4)
	dp[5]=1 (3 1 1) (4 1) (1 4)
	두 사람이 완벽하게 게임을 하는데 상근이가 먼저 시작하니까 상근이가 이김
	dp[6]=1 (4 1 1)
	dp[7]=0 (4 3) (3 4) (1 4 1 1) <= 어떤 경우에도 상근이가 진다.

	=> dp[i]가 상근이의 차례라면,
	dp[i-1] dp[i-3] dp[i-4]가 창영이의 차례가 된다.

	==> 따라서, dp[i-1] dp[i-3] dp[i-4] 에서 하나라도 0인 것이 있어야 상근이가 이긴다.
	*/
	
	dp[1] = dp[3] = dp[4] = dp[5] = 1;
	dp[2] = 0;

	for (int i = 6; i <= n; i++) {
		if (dp[i - 1] == 0 || dp[i - 3] == 0 || dp[i - 4] == 0) dp[i] = 1;
		else dp[i] = 0;
	}

	//결과 출력
	if (dp[n] == 1) cout << "SK\n";
	else cout << "CY\n";
}