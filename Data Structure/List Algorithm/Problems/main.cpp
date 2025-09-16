#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next = nullptr;

    explicit Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

Node* head = nullptr;
Node* tail = nullptr;

void addLast(int data) {
    Node* newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void display() {
    Node* current = head;

    while (current != nullptr) {
        if (current->next == nullptr) {
            cout << current->data;
        } else {
            cout << current->data << ", ";
        }

        current = current->next;
    }

    cout << endl;
}

int midElement() {
    if (head == nullptr) return -1;

    Node* fast = head;
    Node* slow = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int occurrences(int value) {
    if (head == nullptr) return -1;
    Node* temp = head;
    int count = 0;

    while (temp != nullptr) {
        if (temp->data == value) {
            count++;
        }
        temp = temp->next;
    }

    return count;
}

void sortedAdd(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = tail = newNode;
        return;
    }

    if (value <= head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->data < value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        tail->next = newNode;
        tail = newNode;
        return;
    }

    prev->next = newNode;
    newNode->next = temp;
}

void delEven() {
    if (head == nullptr) {
        cout << "List is empty";
        return;
    }



}

int main() {
    int choice;
    int count = 0;

    while (true) {
        cout << "1. Add element\n"
                "2. Display\n"
                "3. Total elements\n"
                "4. Middle Element\n"
                "5. Find occurrences of a number\n"
                "6. Add as sorted\n"
                "7. Delete Even"
                "-1. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        if (choice == -1) {
            break;
        }
        else if (choice == 1) {
            int value;
            cout << "Value :";
            cin >> value;
            addLast(value);
            count++;
        }
        else if (choice == 2) {
            display();
        }
        else if (choice == 3) {
            cout << "Elements cound: " << count << endl;
        }
        else if (choice == 4) {
            int data = midElement();

            if (data == -1) {
                cout << "List is empty";
            }
            else {
                cout << "Middle: " << data;
            }

            cout << endl;
        }
        else if (choice  == 5) {
            int value;

            cout << "Value: ";
            cin >> value;

            int total = occurrences(value);

            if (total == -1) {
                cout << "List is empty";
            }
            else {
                cout << "Total occurrences: " << total << endl;
            }
        }
        else if (choice == 6){
            int value;

            cout << "value: ";
            cin >> value;

            sortedAdd(value);
        }
        else if (choice == 7) {
            delEven();
        }
    }

    cout << head->data << "\n" << tail->data;
}