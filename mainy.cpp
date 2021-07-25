#include <iostream>

using namespace std;

class Mydoublelinkedlist{
public:
    struct node{
    int data;
    node* prev;
    node* next;
};

node* head;
node* tail;

Mydoublelinkedlist(){
    head = NULL;
    tail = NULL;
}

void insert_node(node* prev, int new_data){
    node* new_node = new node();
    new_node->data = new_data;
    if(prev == NULL){
        return;
    }

    new_node->next = prev->next;
    if(prev->next != NULL){
        prev->next->prev = new_node;
    }

    prev-> next = new_node;
    new_node->prev = prev;
}

void insert_begin(int new_data){
    node* new_node = new node();
    new_node-> data = new_data;
    if(head == NULL){
        head = new_node;
        tail = new_node;
    }
    else{
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

void insert_end(int new_data){
    node* new_node = new node();
    new_node->data = new_data;
    if(head == NULL){
        head = new_node;
        tail = new_node;
    }
    else{
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}

void delete_node(node*prev){
    if(prev == NULL || prev->next == NULL){
        return;
    }
    node* temp = prev->next;
    prev->next = temp->next;
    if(temp->next != NULL){
        temp->next->prev = prev;
    }
    delete(temp);
}
void delete_begin(){
    if(head == NULL){
        return;
    }
    node* temp = head;
    if(head == tail){
        delete(temp);
        head = NULL;
        tail = NULL;
    }
    else{
        head = head->next;
        head->prev = NULL;
        delete(temp);
    }
}

void delete_end(){
    if(head == NULL){
        return;
    }
    node*temp = tail;
    if(head == tail){
        delete(temp);
        head = NULL;
        tail = NULL;
    }
    else{
        tail = tail->prev;
        tail-> next = NULL;
        delete(temp);
    }
}

bool search_node(int key){
    node* curr = head;
    while(curr-> next != NULL){
        if(curr-> data == key){
            return true;
        }
        curr = curr->next;
    }
    return false;
}

void print_linkedlist(){
    node* curr = head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

// Print linked list in reversed order
void print_linkedlist_reverse(){
    node* curr = tail;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->prev;
    }
    cout<<endl;
}

//- Insert element at position i in linked list
void insert_pos(int i, int new_data){
    if(i == 0){
        insert_begin(new_data);
        return;
    }
    node* new_node = new node();
    new_node->data = new_data;
    node* curr = head;
    int j = 0;
    while(curr != NULL){
        if(j == i){
             new_node->prev = curr->prev;
             curr->prev->next = new_node;
             curr->prev = new_node;
             new_node->next = curr;
             return;
        }
        j++;
        curr = curr->next;
    }
    insert_end(new_data);
}

int elements(){
    node* curr = head;
    int n = 0;
    while(curr != NULL){
        n++;
        curr = curr->next;
    }
    return n;
}

// Delete all elements in linked list by iterative/recursive way
void delete_all(){
     int n = elements();
     n = n - 1;
     while(n >= 0){
            delete_end();
            n--;
     }
}

//Reverse linked list
void reverse_linkedlist(){
    node* curr = head;
    node* temp = NULL;
    int n = elements();
    if(curr == NULL || curr->next == NULL){
        return;
    }
    while(curr != NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    head = temp->prev;
}

//Count number of times which element occurs in linked list by iterative/recursive way
void repetition(int i){
    node* curr = head;
    int n = 0;
    while( curr != NULL){
        if(curr-> data == i){
            n++;
        }
        curr = curr->next;
    }
    cout<<n<<endl;
}

// Intersection of two sorted linked list
void intersection(Mydoublelinkedlist q){
    node* curr = head;
    node* curr2 = q.head;
    while(curr != NULL){
        while(curr2 != NULL){
            if(curr->data == curr2->data){
                cout<<curr->data<<" ";
            }
            curr2 = curr2->next;
        }
        curr2 = q.head;
        curr = curr->next;
    }
}

void removeduplicate(){
    node* curr1 = head;
    node* curr2;
    node* dup;
    while(curr1 != NULL && curr1->next != NULL){
            curr2 = curr1;
            while(curr2 -> next != NULL){
                if(curr1->data == curr2->next->data){
                    dup = curr2->next;
                    curr2->next = curr2->next->next;
                    delete(dup);
                }
                else{
                    curr2 = curr2->next;
                }
            }
            curr1 = curr1->next;
    }
}

//Union of two unsorted linked list
Mydoublelinkedlist union_sorted(Mydoublelinkedlist q){
    Mydoublelinkedlist obj;
    obj.head = head;
    obj.tail = tail;
    obj.tail->next = q.head;
    obj.tail = q.tail;
    obj.removeduplicate();
    return obj;
}

// Segregate even and odd nodes in a linked list
void Segregate(){
    node* curr = head;
    int i = 0;

    while(curr != NULL){
        if(curr->data % 2 == 0){
            insert_pos(i,curr->data);
            delete_node(curr->prev);
            i++;
        }
    curr = curr->next;
    }

}
};

int main()
{
    Mydoublelinkedlist obj;
    obj.insert_end(1);
    obj.insert_end(2);
    obj.insert_end(3);
    obj.insert_end(4);
    Mydoublelinkedlist obj2;
    Mydoublelinkedlist obj3;
    obj2.insert_end(1);
    obj2.insert_end(2);
    obj2.insert_end(7);
    obj2.insert_end(8);


    cout<<"Reverse double linked list: "<<endl;
    obj.print_linkedlist_reverse();

    cout<<"insert 6 at index 2: "<<endl;
    obj.insert_pos(2,6);
    obj.print_linkedlist();

    obj.reverse_linkedlist();
    obj.print_linkedlist();

    cout<<"Repetition of number 2: "<<endl;
    obj.repetition(2);

    cout<<"Intersection between two linked lists: "<<endl;
    obj.intersection(obj2);
    cout<<endl;

    cout<<"Delete all elements: "<<endl;
    obj.delete_all();
    obj.print_linkedlist();

}
