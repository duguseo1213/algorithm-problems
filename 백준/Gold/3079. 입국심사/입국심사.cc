#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <cstring>
using namespace std;

int arr[100001];

int N, M;

long long answer;

int main() {
    
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    long long left = 1;
    long long right = 1000000000000000000;

    while (1) {

        if (left > right) break;

        long long mid = (left + right) / 2;

        long long sum = 0;

        for (int i = 0; i < N; i++) {

            sum += mid / arr[i];
            if (sum >= M) break;

        }

        if (sum >= M) {
            answer = mid;
            right = mid - 1;

        }
        else {
            left = mid + 1;
        }

    }

    cout << answer;


}