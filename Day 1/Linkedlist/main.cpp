#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void insertAfter(int data, int afterData) {
        Node* current = head;
        while (current) {
            if (current->data == afterData) {
                Node* newNode = new Node(data);
                newNode->next = current->next;
                newNode->prev = current;

                if (current->next) {
                    current->next->prev = newNode;
                } else {
                    tail = newNode;
                }
                current->next = newNode;
                size++;
                return;
            }
            current = current->next;
        }
        cout << "Node with data " << afterData << " not found.\n";
    }

    void insertBefore(int data, int beforeData) {
        Node* current = head;
        while (current) {
            if (current->data == beforeData) {
                Node* newNode = new Node(data);
                newNode->next = current;
                newNode->prev = current->prev;

                if (current->prev) {
                    current->prev->next = newNode;
                } else {
                    head = newNode;
                }
                current->prev = newNode;
                size++;
                return;
            }
            current = current->next;
        }
        cout << "Node with data " << beforeData << " not found.\n";
    }

    int getSize() const {
        return size;
    }

    int getDataByIndex(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range.");
        }
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    void printList() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }

    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);

    cout << "Initial list: ";
    list.printList();

    list.insertAfter(25, 20);
    cout << "After inserting 25 after 20: ";
    list.printList();

    list.insertBefore(15, 20);
    cout << "After inserting 15 before 20: ";
    list.printList();

    cout << "Number of nodes: " << list.getSize() << "\n";
    cout << "Data at index 2: " << list.getDataByIndex(2) << "\n";

    return 0;
}
