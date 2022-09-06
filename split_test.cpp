#include <iostream>
#include "split.h"

using namespace std;

void print(Node*&);
void deall(Node*&);

int main() {
    Node* list = new Node(1, NULL);
    Node* cur = list;
    for (int i = 3; i<=5; i+=2) {
        Node* next = new Node(i, NULL);
        cur->next = next;
        cur = next;
    }

    cout << "List:";
    print(list);

    Node* odds = NULL;
    Node* evens = NULL;
    split(list, odds, evens);
    cout << "Odds:";
    print(odds);

    cout << "Evens:";
    print(evens);

    cout << "in:";
    print(list);
    
    deall(odds);
    deall(evens);
    deall(list);
}

void print(Node*& list) {
    if (list == NULL) {
        cout << " NULL";
    } else {
        Node* cur = list;
        while(cur != NULL) {
            cout << " " << cur->value;
            cur = cur->next;
        }
    }
    cout << endl;
}

void deall(Node*& list) {
    Node* cur = list;
    while(cur != NULL) {
        Node* del = cur;
        cur = cur->next;
        delete del;
    }
}