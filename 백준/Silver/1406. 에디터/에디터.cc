#define _CRT_SECURE_NO_WARNINGS
#define P printf
#include <iostream>


using namespace std;

string good;

struct Node {
	char a;
	Node* next;
	Node* prev;
};

Node nds[700000];

Node Head;
Node Tail;

Node cur;

int ncnt;


int q;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> good;

	for (int i = 0; i < good.size(); i++) {

		Node* nd = &nds[ncnt++];

		nd->a = good[i];

		if (Head.next == NULL) {
			nd->next = &Tail;
			nd->prev = &Head;

			Head.next = nd;
			Tail.prev = nd;

		}
		else {

			nd->next = &Tail;
			nd->prev = Tail.prev;

			Tail.prev->next = nd;
			Tail.prev = nd;


		}

	}

	Node* cur = &Tail;

	cin >> q;

	string a;
	char b;
	for (int i = 0; i < q; i++) {
			
		cin >> a;

		if (a == "P") {
			cin >> b;
			Node* nd = &nds[ncnt++];

			nd->a = b;

			nd->next = cur;
			nd->prev = cur->prev;

			cur->prev->next = nd;
			cur->prev = nd;


		}
		else if (a == "B") {
			if (cur->prev != &Head) {

				cur->prev->prev->next = cur;
				cur->prev = cur->prev->prev;

			}


		}
		else if (a == "L") {
			if (cur->prev != &Head) {
				cur = cur->prev;
			}

		}
		else if (a == "D") {
			if (cur != &Tail) {
				cur = cur->next;
			}
		}


	}

	Node* nd = &Head;

	while (1) {

		if (nd == &Tail) break;

		nd = nd->next;
		if (nd == &Tail) break;
		cout << nd->a;

	}



}