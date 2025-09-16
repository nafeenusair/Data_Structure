//Assignment 1
//Name: Quazi Nafee Nusair
//ID  : 0112410026

#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;

    explicit Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

Node* head = nullptr;
Node* tail = nullptr;

void addFirst(int data) {
    Node* newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void addEnd(int data) {
    Node* newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void addAt(int data, int pos) {
    if (pos < 0) {
        cout << "Invalid Position" << endl;
        return;
    }
    else if (pos == 0) {
        addFirst(data);
        return;
    }

    Node* newNode = new Node(data);
    Node* temp = head;
    int i = 0;

    while (i < pos - 1 && temp != nullptr) {
        temp = temp->next;
        i++;
    }

    if (temp == nullptr) {
        cout << "List is out of bound" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    } else {
        tail = newNode;
    }

    temp->next = newNode;
}

void delFirst() {
    if (head == nullptr) {
        cout << "List is Empty";
        return;
    }

    Node* temp = head;

    if (head->next == nullptr) {
        head = nullptr;
        tail = nullptr;
    }
    else {
        head = head->next;
        head->prev = nullptr;
    }

    delete temp;
}

void delEnd() {
    if (head == nullptr) {
        cout << "List is empty";
        return;
    }

    Node* temp = tail;

    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node* temp2 = temp->prev;
        temp2->next = nullptr;
        tail = temp2;
    }

    delete temp;
}

void delAt(int pos) {
    if (head == nullptr) {
        cout << "List is empty";
        return;
    }

    if (pos < 0) {
        cout << "List is out of bound";
        return;
    }
    else if (pos == 0) {
        delFirst();
        return;
    }

    Node* temp = head;
    int i = 0;

    while (i < pos - 1 && temp != nullptr) {
        temp = temp->next;
        i++;
    }

    if (temp == nullptr) {
        cout << "Position is out of bound";
        return;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    else {
        tail = temp->prev;
    }

    delete temp;
}

void delByVal(int data) {
    if (head == nullptr) {
        cout << "List is empty";
        return;
    }

    Node* temp = head;

    while (temp != nullptr && temp->data != data) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Data : " << data << "is not in the list";
        return;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    else {
        head = temp->next;
    }

    if (temp->next == nullptr) {
        tail = temp->prev;
    }

    delete temp;
}

void display() {
    if (head == nullptr) {
        cout << "List is Empty";
        return;
    }

    Node* temp = head;
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void countNode() {
    if (head == nullptr) {
        cout << "List is Empty";
        return;
    }

    Node* temp = head;
    int count = 0;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    cout << "Total Node is: " << count;
    cout << endl;
}

int linearSearch(int data) {
    if (head == nullptr) {
        return -1;
    }

    Node* temp = head;
    int i = 0;

    while (temp != nullptr) {
        if (temp->data == data) {
            return i;
        }
        temp = temp->next;
        i++;
    }

    return -1;
}

void maxMin() {
    if (head == nullptr) {
        cout << "List is Empty";
        return;
    }

    Node* temp1 = head;
    Node* temp2 = head;

    int max = temp1->data;
    int min = temp2->data;

    while (temp1 != nullptr) {
        if (max < temp1->data) {
            max = temp1->data;
        }
        temp1 = temp1->next;
    }

    while (temp2 != nullptr) {
        if (min > temp2->data) {
            min = temp2->data;
        }
        temp2 = temp2->next;
    }

    cout << "Maximum Value: " << max << endl << "Minimum Value: " << min;
    cout << endl;
}

int sumOfList() {
    if (head == nullptr) {
        return -1;
    }

    int sum = 0;
    Node* temp = head;

    while (temp != nullptr) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

void reverseList() {
    if (head == nullptr) {
        cout << "List is Empty";
        return;
    }

    Node* temp = tail;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }

    cout << endl;
}

void removeDup() {
    if (head == nullptr) {
        cout << "List is Empty";
        return;
    }

    Node* temp = head;

    while (temp != nullptr) {
        int value = temp->data;

        for (Node* i = head; i != nullptr;) {
            Node* nextNode = i->next;

            if (i != temp && i->data == value) {
                if(i->prev != nullptr){
                    i->prev->next = i->next;
                }

                if(i->next != nullptr){
                    i->next->prev = i->prev;
                }
                delete i;
            }

            i = nextNode;
        }
        temp = temp->next;

    }
}

void midOfList() {
    if (head == nullptr) {
        cout << "List is Empty";
        return;
    }

    Node* fast = head;
    Node* slow = head;

    while (fast != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle Element: " << slow->data;
}

void concatenate() {
    Node* head2 = nullptr;
    Node* tail2 = nullptr;

    while (true) {
        int choice1;

        cout << "Second List Menu (No deletion available)\n"
             "1. Add at Beginning\n"
             "2. Add at End\n"
             "3. Add at Position\n"
             "0. Finish and Concatenate\n";
        cout << "Enter your choice: ";
        cin >> choice1;

        if (choice1 == 1) {
            int data;
            cout << "Enter data: ";
            cin >> data;

            Node* newNode = new Node(data);
            if (head2 == nullptr) {
                head2 = tail2 = newNode;
            } else {
                newNode->next = head2;
                head2->prev = newNode;
                head2 = newNode;
            }
        }
        else if (choice1 == 2) {
            int data;
            cout << "Enter data: ";
            cin >> data;

            Node* newNode = new Node(data);
            if (head2 == nullptr) {
                head2 = tail2 = newNode;
            } else if (tail2 != nullptr){
                tail2->next = newNode;
                newNode->prev = tail2;
                tail2 = newNode;
            }
        }
        else if (choice1 == 3) {
            int data, pos;
            cout << "Enter data: ";
            cin >> data;
            cout << "Enter position: ";
            cin >> pos;

            if (pos == 0) {
                Node* newNode = new Node(data);
                if (head2 == nullptr) {
                    head2 = tail2 = newNode;
                } else {
                    newNode->next = head2;
                    head2->prev = newNode;
                    head2 = newNode;
                }
            } else {
                Node* temp = head2;
                int i = 0;
                while (i < pos - 1 && temp != nullptr) {
                    temp = temp->next;
                    i++;
                }
                if (temp == nullptr) {
                    cout << "Position out of bounds!\n";
                } else {
                    Node* newNode = new Node(data);
                    newNode->next = temp->next;
                    newNode->prev = temp;
                    if (temp->next != nullptr)
                        temp->next->prev = newNode;
                    else
                        tail2 = newNode;
                    temp->next = newNode;
                }
            }
        }
        else if (choice1 == 0) {
            break; // exit loop
        }
        else {
            cout << "Invalid Input! Try again...\n";
        }
    }

    if (head2 != nullptr) {
        if (tail != nullptr) {
            tail->next = head2;
            head2->prev = tail;
        } else {
            head = head2;
        }
        tail = tail2;
    }

    cout << "Lists concatenated successfully!\n";
}

int occurrences(int data) {
    if (head == nullptr) return -1;
    Node* temp = head;
    int count = 0;

    while (temp != nullptr) {
        if (temp->data == data) {
            count++;
        }
        temp = temp->next;
    }

    return count;
}

void addSorted(int data) {
    Node* newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }

    if (data < head->data) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->data < data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        return;
    }

    prev->next = newNode;
    temp->prev = newNode;
    newNode->next = temp;
    newNode->prev = prev;
}

void delEven() {
    if (head == nullptr) {
        cout << "List is Empty";
        return;
    }

    while (head != nullptr && head->data % 2 == 0) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    if (head == nullptr) return;

    Node* temp = head;
    while (temp->next != nullptr) {
        if (temp->next->data % 2 == 0) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        } else {
            temp = temp->next;
        }
    }
}

void delOdd() {
    if (head == nullptr) {
        cout << "List is Empty";
        return;
    }

    while (head != nullptr && head->data % 2 != 0) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    if (head == nullptr) return;

    Node* temp = head;
    while (temp->next != nullptr) {
        if (temp->next->data % 2 != 0) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        } else {
            temp = temp->next;
        }
    }
}

int main() {
    int choice;

    while (true) {
        cout << "Menu\n"
             "1. Add at Beginning\n"
             "2. Add at End\n"
             "3. Add at Position\n"
             "4. Delete at Beginning\n"
             "5. Delete at End\n"
             "6. Delete at Position\n"
             "7. Delete by Value\n"
             "8. Display\n"
             "9. Count Nodes\n"
             "10. Linear Search\n"
             "11. Find Max and Min value\n"          
             "13. Reverse Display\n"
             "14. Remove Duplicates\n"
             "15. Middle Element of the List\n"
             "16. Concatenate Two Lists\n"
             "17. Find Occurrences of a Number\n"
             "18. Add Sorted\n"
             "19. Delete Even Number\n"
             "20. Delete Odd Number\n"
             "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int data;
            cout << "Enter data: ";
            cin >> data;

            addFirst(data);
        }
        else if (choice == 2) {
            int data;
            cout << "Enter data: ";
            cin >> data;

            addEnd(data);
        }
        else if (choice == 3) {
            int data, position;
            cout << "Enter Data: ";
            cin >> data;
            cout << "Enter position: ";
            cin >> position;

            addAt(data, position);
        }
        else if (choice == 4) {
            delFirst();
        }
        else if (choice == 5) {
            delEnd();
        }
        else if (choice == 6) {
            int position;
            cout << "Enter the position to delete: ";
            cin >> position;

            delAt(position);
        }
        else if (choice == 7) {
            int data;
            cout << "Enter the data to delete: ";
            cin >> data;

            delByVal(data);
        }
        else if (choice == 8) {
            display();
        }
        else if (choice == 9) {
            countNode();
        }
        else if (choice == 10) {
            int data;

            cout << "Value to search: ";
            cin >> data;
            int num = linearSearch(data);

            if (num == -1) {
                cout << "Number is not found;";
            } else {
                cout << "Value found in position in " << num+1 << endl;
            }
        }
        else if (choice == 11) {
            maxMin();
        }
        else if (choice == 12) {
            int sum = sumOfList();
            if (sum == -1) {
                cout << "List is empty";
            }
            else {
                Node* temp = head;

                while (temp != nullptr) {
                    cout << temp->data;
                    if (temp->next != nullptr) {
                        cout << " + ";
                    }
                    temp = temp->next;
                }

                cout << " = " << sum << endl;
            }
        }
        else if (choice == 13) {
            reverseList();
        }
        else if (choice == 14) {
            removeDup();
        }
        else if (choice == 15) {
            midOfList();
        }
        else if (choice == 16) {
            concatenate();
        }
        else if (choice  == 17) {
            int value;

            cout << "Value: ";
            cin >> value;

            int total = occurrences(value);

            if (total == -1) {
                cout << "List is empty";
            }
            else if (total == 0) {
                cout << "The given value is not in the list once" << endl;;
            }
            else {
                cout << "Total occurrences: " << total << endl;
            }
        }
        else if (choice == 18) {
            int data;

            cout << "Add data: ";
            cin >> data;

            addSorted(data);
        }
        else if (choice == 19) {
            delEven();
        }
        else if (choice == 20) {
            delOdd();
        }
        else if (choice == 0) {
            cout << "Exiting...";
            break;
        }
        else {
            cout << "Invalid Input! Try again..";
        }
    }
}