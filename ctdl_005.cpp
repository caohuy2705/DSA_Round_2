#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* first;

public:
    LinkedList() : first(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (first == nullptr) {
            first = newNode;
        } else {
            Node* current = first;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    int deleteValue(int x) {
        int countDeleted = 0;

        while (first != nullptr && first->data == x) {
            Node* temp = first;
            first = first->next;
            delete temp;
            countDeleted++;
        }

        Node* current = first;
        while (current != nullptr && current->next != nullptr) {
            if (current->next->data == x) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                countDeleted++;
            } else {
                current = current->next;
            }
        }

        return countDeleted;
    }

    void display() {
        Node* current = first;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;
    int n, x, input;
    std::cout << "Nhap so luong phan tu trong danh sach: ";
    std::cin >> n;

    std::cout << "Nhap " << n << " phan tu: ";
    for (int i = 0; i < n; i++) {
        std::cin >> input;
        list.insert(input);
    }

    std::cout << "Nhap so can xoa: ";
    std::cin >> x;

    int countDeleted = list.deleteValue(x);

    std::cout << "Cac phan tu con lai trong danh sach sau khi xoa " << x << " la: ";
    list.display();

    std::cout << "\nSo luong phan tu da xoa: " << countDeleted << std::endl;

    return 0;
}
