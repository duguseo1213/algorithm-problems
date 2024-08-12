#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <queue>

using namespace std;

priority_queue<int, vector<int>> maxheap;
priority_queue<int, vector<int>,greater<int>> minheap;



int N;

int main() {

    scanf("%d", &N);

    minheap.push(21e8);
    maxheap.push(-21e8);

    for (int i = 0; i < N; i++) {

        int num;
        scanf("%d", &num);

        if (num > minheap.top()) {
            minheap.push(num);
        }
        else {
            maxheap.push(num);
        }

        if (minheap.size() > maxheap.size()) {
            int temp = minheap.top();
            minheap.pop();
            maxheap.push(temp);
        }
        else if(minheap.size()+1<maxheap.size()){
            int temp = maxheap.top();
            maxheap.pop();
            minheap.push(temp);
        }

        printf("%d\n", maxheap.top());




    }

    

}