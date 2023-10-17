#include <iostream>

using namespace std;

// �?nh nghia c?u tr�c c?a m?t node trong danh s�ch li�n k?t don
struct Node {
    int data;
    Node* next;
};

// H�m t?o m?t node m?i v?i gi� tr? du?c cung c?p v� con tr? next tr? d?n nullptr
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// H�m ch�n m?t node m?i v�o d?u danh s�ch li�n k?t
void insertAtBeginning(Node*& first, int value) {
    Node* newNode = createNode(value);
    newNode->next = first;
    first = newNode;
}

// H�m x�a t?t c? c�c ph?n t? c� gi� tr? b?ng x v� tr? v? s? lu?ng c�c ph?n t? d� x�a
int deleteValue(Node*& first, int x) {
    int deletedCount = 0;

    Node* current = first;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->data == x) {
            Node* temp = current;
            current = current->next;
            delete temp;
            deletedCount++;
            if (previous != nullptr) {
                previous->next = current;
            } else {
                first = current;
            }
        } else {
            previous = current;
            current = current->next;
        }
    }

    return deletedCount;
}

// H�m li?t k� c�c ph?n t? c�n l?i trong danh s�ch li�n k?t
void printList(Node* first) {
    Node* current = first;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
}

// H�m gi?i b�i to�n
void solve() {
    int n;
    cin >> n;

    Node* first = nullptr;

    // �?c d? li?u v� ch�n c�c ph?n t? v�o danh s�ch li�n k?t
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertAtBeginning(first, value);
    }

    int x;
    cin >> x;

    // X�a c�c ph?n t? c� gi� tr? b?ng x v� l?y s? lu?ng c�c ph?n t? d� x�a
    int deletedCount = deleteValue(first, x);

    // In danh s�ch c�n l?i sau khi d� x�a
    printList(first);
    cout << endl;

    // Gi?i ph�ng b? nh?
    while (first != nullptr) {
        Node* temp = first;
        first = first->next;
        delete temp;
    }
}

int main() {
    solve();
    return 0;
}

