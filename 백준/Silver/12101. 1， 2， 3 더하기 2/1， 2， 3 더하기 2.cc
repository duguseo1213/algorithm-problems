#define P
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;


int N, K;

vector<int> vec;

vector<string> strs;


void dfs(int sum) {
	//printf("%d\n", sum);
	if (N < sum) {
		return;
	}

	if (N == sum) {
		string temp = "";

		for (int i = 0; i < vec.size()-1; i++) {
			temp += to_string(vec[i]);
			temp += "+";
		}
		temp += to_string(vec[vec.size() - 1]);

		strs.push_back(temp);
		//printf("%s\n", temp.c_str());
		return;
	}


	vec.push_back(1);
	dfs(sum + 1);
	vec.pop_back();

	vec.push_back(2);
	dfs(sum + 2);
	vec.pop_back();

	vec.push_back(3);
	dfs(sum + 3);
	vec.pop_back();



}




int main(){

	scanf("%d %d", &N, &K);

	dfs(0);

	if (strs.size() < K) {
		printf("-1\n");
	}
	else {
		printf("%s\n", strs[K-1].c_str());
	}

}