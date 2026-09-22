#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class LinkedList
{
    Node* head;

public:
    LinkedList()
    {
        head = NULL;
    }

    // Insert at beginning
    void insertBeginning(int value)
    {
        Node* newNode = new Node(value);

        newNode->next = head;
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
    }

    // Insert at a given position
    void insertPosition(int value, int position)
    {
        if (position == 1)
        {
            insertBeginning(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Invalid position" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
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

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
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

        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL)
        {
            cout << "Invalid position" << endl;
            return;
        }

        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;

        delete deleteNode;
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
                cout << "Element found at position " << position << endl;
                return;
            }

            temp = temp->next;
            position++;
        }

        cout << "Element not found" << endl;
    }

    // Display the list
    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

  

  
    
};

int main()
{
    LinkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);

    cout << "Original list: ";
    list.display();

    list.insertBeginning(5);

    cout << "After inserting at beginning: ";
    list.display();

    list.insertPosition(15, 3);

    cout << "After inserting at position 3: ";
    list.display();

    list.deleteBeginning();

    cout << "After deleting from beginning: ";
    list.display();

    list.deleteEnd();

    cout << "After deleting from end: ";
    list.display();

    list.deletePosition(2);

    cout << "After deleting position 2: ";
    list.display();

    list.search(20);

    cout << "Number of nodes: " << list.countNodes() << endl;

    list.reverse();

    cout << "After reversing: ";
    list.display();

    return 0;
}
