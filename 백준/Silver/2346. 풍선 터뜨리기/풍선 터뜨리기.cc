#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>


using namespace std;

struct Node {

	int id;
	int value;

	Node* next;
	Node* prev;
};

Node nds[1011];

Node Head;
Node Tail;

int N;

int main() {
	
	Head.id = 10000;
	Tail.id = -10000;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {

		Node* temp=&nds[i];
		int good;
		scanf("%d", &good);
		temp->id = i;
		temp->value = good;
		//printf("%d", good);
		if (Head.next == NULL) {

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

	Node* temp = Head.next;
	printf("%d ", temp->id);
	int value = temp->value;

	Node* temp2 = temp;

	


	if (value > 0) {

		if (temp->next->id == -10000) {

			temp = Head.next;
		}
		else {
			temp = temp->next;
		}

		temp2->prev->next = temp2->next;
		temp2->next->prev = temp2->prev;


		for (int i = 0; i < value-1; i++) {

			if (temp->next->id == -10000) {

				temp = Head.next;
			}
			else {
				temp = temp->next;
			}

		}

	}
	else {

		if (temp->prev->id == 10000) {

			temp = Tail.prev;
		}
		else {
			temp = temp->prev;
		}

		temp2->prev->next = temp2->next;
		temp2->next->prev = temp2->prev;

		for (int i = 0; i < value*-1-1; i++) {

			if (temp->prev->id == 10000) {

				temp = Tail.prev;
			}
			else {
				temp = temp->prev;
			}

		}
	}

	
	


	for (int i = 1; i < N-1; i++) {

		
		printf("%d ", temp->id);

		value = temp->value;
		temp2 = temp;

		if (value > 0) {

			if (temp->next->id == -10000) {

				temp = Head.next;
			}
			else {
				temp = temp->next;
			}

			temp2->prev->next = temp2->next;
			temp2->next->prev = temp2->prev;


			for (int i = 0; i < value - 1; i++) {

				if (temp->next->id == -10000) {

					temp = Head.next;
				}
				else {
					temp = temp->next;
				}

			}

		}
		else {

			if (temp->prev->id == 10000) {

				temp = Tail.prev;
			}
			else {
				temp = temp->prev;
			}

			temp2->prev->next = temp2->next;
			temp2->next->prev = temp2->prev;

			for (int i = 0; i < value * -1-1; i++) {

				if (temp->prev->id == 10000) {

					temp = Tail.prev;
				}
				else {
					temp = temp->prev;
				}

			}
		}

		


	}
	printf("%d ", temp->id);


}