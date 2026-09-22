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

class CircularList
{
    Node* head;

public:
    CircularList()
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
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    // Insert at end
    void insertEnd(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    // Insert at a given position
    void insertPosition(int value, int position)
    {
        if (position == 1)
        {
            insertBeginning(value);
            return;
        }

        if (head == NULL)
        {
            cout << "Invalid position" << endl;
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;

            if (temp == head)
            {
                cout << "Invalid position" << endl;
                return;
            }
        }

        Node* newNode = new Node(value);

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

        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        Node* last = head;

        while (last->next != head)
        {
            last = last->next;
        }

        head = head->next;
        last->next = head;

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

        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        while (temp->next->next != head)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = head;
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

        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;

            if (temp == head)
            {
                cout << "Invalid position" << endl;
                return;
            }
        }

        if (temp->next == head)
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
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        int position = 1;

        do
        {
            if (temp->data == value)
            {
                cout << "Element found at position "
                     << position << endl;
                return;
            }

            temp = temp->next;
            position++;

        } while (temp != head);

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

        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;

        } while (temp != head);

        cout << "HEAD" << endl;
    }

    // Count nodes
    int countNodes()
    {
        if (head == NULL)
        {
            return 0;
        }

        int count = 0;
        Node* temp = head;

        do
        {
            count++;
            temp = temp->next;

        } while (temp != head);

        return count;
    }

    // Reverse the circular linked list
    void reverse()
    {
        if (head == NULL || head->next == head)
        {
            return;
        }

        Node* previous = NULL;
        Node* current = head;
        Node* nextNode;

        do
        {
            nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;

        } while (current != head);

        head->next = previous;
        head = previous;
    }
};

int main()
{
    CircularList list;

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

    cout << "Number of nodes: "
         << list.countNodes() << endl;

    list.reverse();

    cout << "After reversing: ";
    list.display();

    return 0;
}
