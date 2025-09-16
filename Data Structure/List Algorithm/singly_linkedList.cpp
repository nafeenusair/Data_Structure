#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* link;

    explicit Node(int data) {
        this->data = data;
        this->link = nullptr;
    }
};

Node* head = nullptr;

void displayList() {
    if (head == nullptr) {
        cout << "List is empty" << endl;;
        return;
    }

    Node* temp = head;
    cout << "List : ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->link;
    }

    cout << endl;
}

void addFirst(int data) {
    Node* newNode = new Node(data);
    newNode->link = head;
    head = newNode;
}

void addLast(int data) {
    Node* newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
        return;
    }
    else {
        Node* temp = head;
        while (temp->link != nullptr) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

void addAt(int data, int position) {
    if (position < 0) {
        cout << "Invalid position! Try Again";
        return;
    }

    if (position == 0) {
        addFirst(data);
        return;
    }

    if (head == nullptr) {
        cout << "List is Empty";
        return;
    }

    Node* newNode = new Node(data);
    Node* temp = head;

    for (int i = 0; i < position - 1 && temp != nullptr; i++) {
        temp = temp->link;
    }

    if (temp == nullptr) {
        cout << "Invalid Position! Try Again";
        delete newNode;
        return;
    }

    newNode->link = temp->link;
    temp->link = newNode;

}

void delFirst() {
    if (head == nullptr) {
        cout << "List is empty" << endl;;
        return;
    }

    Node* temp = head;
    head = head->link;
    delete temp;
    cout << "deletion successful" << endl;
}

void delLast() {
    if (head == nullptr) {
        cout << "List is Empty" << endl;
    }
    Node* temp = head;

    while (temp->link->link != nullptr) {
        temp = temp->link;
    }

    delete temp->link;
    temp->link = nullptr;

    cout << "deletion successful" << endl;
}

void delAt(int position) {
    if (position < 0) {
        cout << "Invalid position! Try Again";
        return;
    }

    if (position == 0) {
        delFirst();
        return;
    }

    if (head == nullptr) {
        cout << "List is Empty";
        return;
    }

    Node* temp = head;
    for (int i = 0; i < position - 1 && temp != nullptr; i++) {
        temp = temp->link;
    }

    if (temp == nullptr || temp->link == nullptr) {
        cout << "Position out of range.\n";
        return;
    }

    Node* delNode = temp->link;
    temp->link = delNode->link;
    delete delNode;
    cout << "Node deleted at position " << position << ".\n";
}

void delValue(int value) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    if (head->data == value) {
        delFirst();
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->link;
    }

    if (temp == nullptr) {
        cout << "Value doesn't exist" << endl;
        return;
    }

    prev->link = temp->link;
    delete temp;
    cout << "deletion successful" << endl;
}

int main() {
    int choice;

    while (true) {
        cout << "Singly LinkedList\n"
            "1. Display List\n"
            "2. Add at beginning\n"
            "3. Add at the end\n"
            "4. Add at a position\n"
            "5. Delete at beginning\n"
            "6. Delete at End\n"
            "7. Delete at position\n"
            "8. Delete a value\n"
            "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            displayList();
        }
        else if (choice == 2) {
            int data;
            cout << "Enter the value: ";
            cin >> data;

            addFirst(data);
        }
        else if (choice == 3) {
            int data;
            cout << "Enter the value: ";
            cin >> data;

            addLast(data);
        }
        else if (choice == 4) {
            int data, position;
            cout << "Enter position: ";
            cin >> position;
            cout << "Enter the value: ";
            cin >> data;

            addAt(data, position);
        }
        else if (choice == 5) {
            delFirst();
        }
        else if (choice == 6) {
            delLast();
        }
        else if (choice == 7) {
            int position;
            cout << "Enter postion: ";
            cin >> position;

            delAt(position);
        }
        else if (choice == 8) {
            int data;
            cout << "Enter value to delete: ";
            cin >> data;

            delValue(data);
        }
        else if (choice == 0) {
            cout << "Exiting....";
            break;
        }
        else {
            cout << "Invalid Input! Try Again...";
        }

        cout << endl;
    }
}