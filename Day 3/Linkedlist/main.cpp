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

    int linearSearch(int value) {
        Node* current = head;
        int index = 0;
        while (current) {
            if (current->data == value) return index;
            current = current->next;
            index++;
        }
        return -1;
    }

void bubbleSort() {
    if (!head) return;
    for (int i = 0; i < size - 1; i++) {
        Node* current = head;
        for (int j = 0; j < size - i - 1; j++) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }
            current = current->next;
        }
    }
}


int binarySearch(int value) {
    int left = 0, right = size - 1;

    while (left <right) {
        int mid = (left + right) / 2;
        Node* midNode = getNodeByIndex(mid);

        if (midNode->data == value) return mid;
        if (midNode->data < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

Node* getNodeByIndex(int index) {
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        if (current) current = current->next;
    }
    return current;
}


    void printList() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

int main() {
    DoublyLinkedList list;

    list.append(45);
    list.append(12);
    list.append(78);
    list.append(34);
    list.append(90);
    list.append(23);
    list.append(56);
    list.append(67);
    list.append(89);
    list.append(11);

    cout << "Initial list: ";
    list.printList();

    cout << "Linear search for 56: " << list.linearSearch(56) << "\n";
    cout << "Linear search for 100 (not present): " << list.linearSearch(100) << "\n";

    list.bubbleSort();
    cout << "List after bubble sort: ";
    list.printList();

    cout << "Binary search for 23: " << list.binarySearch(23) << "\n";
    cout << "Binary search for 100 (not present): " << list.binarySearch(100) << "\n";

    return 0;
}

