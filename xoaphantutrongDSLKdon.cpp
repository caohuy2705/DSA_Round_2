#include <iostream>

using namespace std;

// Ð?nh nghia c?u trúc c?a m?t node trong danh sách liên k?t don
struct Node {
    int data;
    Node* next;
};

// Hàm t?o m?t node m?i v?i giá tr? du?c cung c?p và con tr? next tr? d?n nullptr
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Hàm chèn m?t node m?i vào d?u danh sách liên k?t
void insertAtBeginning(Node*& first, int value) {
    Node* newNode = createNode(value);
    newNode->next = first;
    first = newNode;
}

// Hàm xóa t?t c? các ph?n t? có giá tr? b?ng x và tr? v? s? lu?ng các ph?n t? dã xóa
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

// Hàm li?t kê các ph?n t? còn l?i trong danh sách liên k?t
void printList(Node* first) {
    Node* current = first;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
}

// Hàm gi?i bài toán
void solve() {
    int n;
    cin >> n;

    Node* first = nullptr;

    // Ð?c d? li?u và chèn các ph?n t? vào danh sách liên k?t
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertAtBeginning(first, value);
    }

    int x;
    cin >> x;

    // Xóa các ph?n t? có giá tr? b?ng x và l?y s? lu?ng các ph?n t? dã xóa
    int deletedCount = deleteValue(first, x);

    // In danh sách còn l?i sau khi dã xóa
    printList(first);
    cout << endl;

    // Gi?i phóng b? nh?
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

