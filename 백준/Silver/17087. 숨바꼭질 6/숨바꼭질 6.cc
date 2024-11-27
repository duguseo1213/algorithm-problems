#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

using namespace std;

int N, S;

int arr[100001];

int gcd(int a, int b) {

    int temp;
    while (1) {

        if (a % b == 0) return b;

        temp = a % b;
        a = b;
        b = temp;


    }

}


int main() {
    

    scanf("%d %d", &N, &S);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < N; i++) {

        if (arr[i] > S) {
            arr[i] = arr[i] - S;
        }
        else {
            arr[i] =S-arr[i];
        }
    }

    int temp = arr[0];

    for (int i = 1; i < N; i++) {
        temp = gcd(temp, arr[i]);
    }

    printf("%d", temp);


}
