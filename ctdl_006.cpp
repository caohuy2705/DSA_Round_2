#include <iostream>
#include <unordered_set>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* First;

    LinkedList() : First(nullptr) {}

    void append(int value) {
        Node* newNode = new Node(value);
        if (First == nullptr) {
            First = newNode;
        } else {
            Node* current = First;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void removeDuplicates() {
        if (First == nullptr) return;

        std::unordered_set<int> seenValues;
        Node* current = First;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (seenValues.find(current->data) == seenValues.end()) {
                seenValues.insert(current->data);
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

    void display() {
        Node* current = First;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;
    int n;

    //std::cout << "Nhap so luong phan tu trong danh sach: ";
    std::cin >> n;

    //std::cout << "Nhap cac phan tu: ";
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        list.append(value);
    }

    //std::cout << "Danh sach truoc khi loc trung: ";
    //list.display();

    list.removeDuplicates();

    //std::cout << "Danh sach sau khi loc trung: ";
    list.display();

    return 0;
}
