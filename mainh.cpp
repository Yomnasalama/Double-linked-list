#include <bits/stdc++.h>
using namespace std;

class myList
{

public:

    struct node {
        int data;
        node* prev;
        node* next;
    };
    node* head;
    node* tail;

    myList()
    {
        head = NULL;
        tail = NULL;
    }

    void insert(int new_data) {
        node* new_node = new node();
        new_node->data = new_data;
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        }

        else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    int countElementsIterative()
    {
        int counter = 0;
        node* current = head;
        while(current != NULL)
        {
            counter++;
            current = current->next;
        }
        return counter;
    }

    int countElementsRecursive(node* head)
    {
        if (head == NULL) {
            return 0;
        }
        else {
            return 1 + countElementsRecursive(head->next);
        }
    }

    void printElemetAtMiddle()
    {
        int counter = countElementsIterative();
        if(counter & 2 == 0)
            counter = counter / 2;
        else
            counter = (counter + 1) / 2;
        node* current = head;
        for(int i = 0; i < counter - 1; i++)
        {
            current = current->next;
            cout << current->data << endl;
        }
        cout << current->data << endl;
    }

    void print()
    {
        node* curr = head;
        while (curr != NULL) {
            cout << curr->data << ' ';
            curr = curr->next;
        }
    }

    void deleteNode(int position)
    {

        if (head == NULL)
            return;
        node* temp = head;

        if (position == 0)
        {
            head = temp->next;
            delete(temp);
            return;
        }

        for(int i = 0; temp != NULL && i < position - 1; i++)
            temp = temp->next;

        if (temp == NULL || temp->next == NULL)
            return;
        node* temp2 = temp->next->next;
        delete(temp->next);
        temp->next = temp2;
    }

    bool searchIterative(int value)
    {
        node* current = head;
        while (current != NULL)
        {
            if (current->data == value)
                return true;
            current = current->next;
        }
        return false;
    }

    bool searchRecursive(node* head,int value)
    {
        if (head == NULL)
            return false;
        if (head->data == value)
            return true;
        return searchRecursive(head->next, value);
    }
};





int main() {
    myList obj;
    obj.insert(1);
    obj.insert(2);
    obj.insert(3);
    obj.insert(4);
    obj.insert(5);
    obj.insert(6);
    cout << obj.searchIterative(5) << endl;
    cout << obj.searchRecursive(obj.head,2) << endl;
    cout << obj.searchRecursive(obj.head,12) << endl;



}

