#include <iostream>
#include <vector>
#include <string>
using namespace std;

int fail[1000001];
string a, b;
vector<int> answer;
int cnt;
void find_fail() {

	fail[0] = -1;

	for (int i = 1; i < b.size(); i++) {

		int j = fail[i - 1];

		while (1) {

			if (j == -1) {
				break;
			}

			if (b[i] == b[j + 1]) {
				break;
			}

			j = fail[j];

		}

		if (b[i] == b[j + 1]) {
			fail[i] = j + 1;
		}
		else {
			fail[i] = -1;
		}

	}



}

void kmp() {

	int i = 0;
	int j = 0;

	while (i < a.size()) {

		while (i < a.size() && j < b.size()) {

			if (a[i] == b[j]) {
				i++;
				j++;
			}
			else if (j == 0) {
				i++;
			}
			else {

				j = fail[j - 1] + 1;

			}

		}
		if (j == b.size()) {
			j = fail[j - 1] + 1;
			answer.push_back(i - b.size() + 1);
			cnt++;
		}

	}


}


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	getline(cin, a);
	getline(cin, b);

	find_fail();
	kmp();

	cout << cnt << "\n";

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}

}