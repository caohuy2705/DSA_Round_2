#include <iostream>
#include <unordered_set>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};


void insert(Node*& first, int value) {
    Node* newNode = new Node(value);
    if (!first) {
        first = newNode;
    } else {
        Node* temp = first;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void filterDuplicates(Node*& first) {
    unordered_set<int> uniqueValues;
    Node* current = first;
    Node* prev = nullptr;

    while (current) {
        if (uniqueValues.find(current->data) == uniqueValues.end()) {
            uniqueValues.insert(current->data);
            prev = current;
            current = current->next;
        } else {
            Node* temp = current;
            current = current->next;
            prev->next = current;
            delete temp;
        }
    }
}

void printLinkedList(Node* first) {
    Node* current = first;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << std::endl;
}

int main() {
    Node* first = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        insert(first, value);
    }

    filterDuplicates(first);
    printLinkedList(first);

    Node* temp;
    while (first) {
        temp = first;
        first = first->next;
        delete temp;
    }

    return 0;
}

