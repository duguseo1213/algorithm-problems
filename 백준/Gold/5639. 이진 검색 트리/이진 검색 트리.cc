#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> vec;
void dfs(int left,int right) {

	if (left >= right) return;
	int temp = vec[left];
	int l = left + 1;
	int r = right-1;
	int answer= left + 1;
	while (1) {

		if (l > r) break;

		int mid = (l + r) / 2;

		if (temp > vec[mid]) {
			l = mid + 1;	
		}
		else {
			r = mid - 1;
			answer = mid;
		}
	}

	//printf("%d ", answer);

	dfs(left + 1, answer);

	dfs(answer, right);

	printf("%d ", temp);

}

int main() {
	int temp;
	while (1) {
		if (scanf("%d", &temp) == EOF) break;
		if (temp == 0) break;
		vec.push_back(temp);

	}
	dfs(0, vec.size());
}