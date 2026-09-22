#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value)
    {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

class DoublyList
{
    Node* head;

public:
    DoublyList()
    {
        head = NULL;
    }

    // Insert at beginning
    void insertBeginning(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at end
    void insertEnd(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Insert at a given position
    void insertPosition(int value, int position)
    {
        if (position == 1)
        {
            insertBeginning(value);
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Invalid position" << endl;
            return;
        }

        Node* newNode = new Node(value);

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }

    // Delete from beginning
    void deleteBeginning()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }

        delete temp;
    }

    // Delete from end
    void deleteEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->prev->next = NULL;

        delete temp;
    }

    // Delete from a given position
    void deletePosition(int position)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (position == 1)
        {
            deleteBeginning();
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Invalid position" << endl;
            return;
        }

        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }

        temp->prev->next = temp->next;

        delete temp;
    }

    // Search an element
    void search(int value)
    {
        Node* temp = head;
        int position = 1;

        while (temp != NULL)
        {
            if (temp->data == value)
            {
                cout << "Element found at position "
                     << position << endl;
                return;
            }

            temp = temp->next;
            position++;
        }

        cout << "Element not found" << endl;
    }

    // Display from beginning to end
    void displayForward()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    // Display from end to beginning
    void displayBackward()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        while (temp != NULL)
        {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }

        cout << "NULL" << endl;
    }

    // Count nodes
    int countNodes()
    {
        int count = 0;
        Node* temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // Reverse the doubly linked list
    void reverse()
    {
        Node* temp = NULL;
        Node* current = head;

        while (current != NULL)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

            current = current->prev;
        }

        if (temp != NULL)
        {
            head = temp->prev;
        }
    }
};

int main()
{
    DoublyList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);

    cout << "Original list: ";
    list.displayForward();

    list.insertBeginning(5);

    cout << "After inserting at beginning: ";
    list.displayForward();

    list.insertPosition(15, 3);

    cout << "After inserting at position 3: ";
    list.displayForward();

    list.deleteBeginning();

    cout << "After deleting from beginning: ";
    list.displayForward();

    list.deleteEnd();

    cout << "After deleting from end: ";
    list.displayForward();

    list.deletePosition(2);

    cout << "After deleting position 2: ";
    list.displayForward();

    list.search(20);

    cout << "Number of nodes: "
         << list.countNodes() << endl;

    cout << "Forward: ";
    list.displayForward();

    cout << "Backward: ";
    list.displayBackward();

    list.reverse();

    cout << "After reversing: ";
    list.displayForward();

    return 0;
}
