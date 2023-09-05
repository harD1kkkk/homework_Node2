// zavd_77.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Node.h"
using namespace std;

void putNodeToTail(Node*& head, int value) {
    Node* n = new Node(value);
    if (head == nullptr) {
        head = n;
        return;
    }
    Node* tmp = nullptr;
    tmp = head;

    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = n;
}

void display(Node* head) {
    Node* temp;
    temp = head;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

void growth(Node*& head) {
    Node* temp = head;
    while (temp->next != nullptr) {
        if (temp->value >= temp->next->value) {
            cout << "No" << endl;
            return;
        }

        temp = temp->next;
    }
    cout << "Yes" << endl;
}

bool same(Node* head) {
    Node* first = head;
    while (first != nullptr) {
        Node* second = first->next;
        while (second != nullptr) {
            if (first->value == second->value) {
                cout << "Yes" << endl;
                return true;
            }
            second = second->next;
        }
        first = first->next;
    }
    cout << "No" << endl;
    return false;
}


void change(Node*& head) {
    Node* temp = head;
    while (temp != nullptr && temp->next != nullptr) {
        int tmpValue = temp->value;
        temp->value = temp->next->value;
        temp->next->value = tmpValue;
        temp = temp->next->next;
    }
}


void isSublist(Node* L1, Node* L2) {
    Node* temp1 = L1;
    Node* temp2 = L2;
    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->value == temp2->value) {
            temp1 = temp1->next;
        }
        temp2 = temp2->next;
    }
    if (temp1 == nullptr) {
        cout << "Yes, the first list is a sublist of the second list" << endl;
    }
    else {
        cout << "No, the first list is not a sublist of the second list" << endl;
    }
}


int main()
{
    Node* head = nullptr;
    int size;
    int number = 0;
    cout << "Enter size: ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        cout << "Enter number: ";
        cin >> number;
        putNodeToTail(head, number);
    }
    display(head);
    int choice;
    do {
        cout << "Make your choice" << endl;
        cout << "1 - Check if the list is in non-decreasing order" << endl;
        cout << "2 - Check if the list contains a pair of elements with the same value" << endl;
        cout << "3 - Swap adjacent elements in the list" << endl;
        cout << "4 - Check if one list is a sublist of another list" << endl;
        cout << "5 - Exit the program" << endl;
        cin >> choice;
        if (choice == 1) {
            growth(head);
            display(head);
        }
        else if (choice == 2) {
            same(head);
            display(head);
        }
        else if (choice == 3) {
            change(head);
            display(head);
        }
        else if (choice == 4) {
            Node* L1 = nullptr;
            Node* L2 = nullptr;
            int size1, size2, number1, number2;
            cout << "Enter size of first list: ";
            cin >> size1;
            for (int i = 0; i < size1; i++) {
                cout << "Enter number: ";
                cin >> number1;
                putNodeToTail(L1, number1);
            }
            display(L1);
            cout << "Enter size of second list: ";
            cin >> size2;
            for (int i = 0; i < size2; i++) {
                cout << "Enter number: ";
                cin >> number2;
                putNodeToTail(L2, number2);
            }
            display(L2);
            isSublist(L1, L2);
        }
        else if (choice != 5) {
            cout << "Invalid choice" << endl;
        }
    } while (choice != 5);
}

