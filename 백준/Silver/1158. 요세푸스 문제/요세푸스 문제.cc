#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>//memset
#include <string>
#include <vector>

using namespace std;

struct Node {

	int id;
	Node* next;
	Node* prev;

};

Node nds[100001];

Node Head;
Node Tail;

int N, K;

int main() {
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {

		Node* temp = &nds[i];
		temp->id = i;

		if (Head.next == NULL){
			
			Head.next = temp;
			Tail.prev = temp;
			temp->next = &Tail;
			temp->prev = &Head;
		}
		else {
			
			temp->next = &Tail;
			temp->prev = Tail.prev;

			Tail.prev->next = temp;
			Tail.prev = temp;

		}


	}

	/*
	Node* t = &Tail;

	while (1) {

		if (t->prev == NULL) break;
		t = t->prev;
		printf("%d ", t->id);


	}*/
	
	printf("<");
	Node* temp = Head.next;

	for (int i = 0; i < N-1; i++) {

		for (int j = 0; j < K-1; j++){

			if (temp->next->id == 0) {
				temp = Head.next;
			}
			else {
				temp = temp->next;
			}
		}

		printf("%d, ", temp->id);

		Node* temp2 = temp;

		if (temp->next->id == 0) {
			temp = Head.next;
		}
		else {
			temp = temp->next;
		}

		temp2->prev->next = temp2->next;
		temp2->next->prev = temp2->prev;


		

		

	}

	printf("%d>", temp->id);
	


}