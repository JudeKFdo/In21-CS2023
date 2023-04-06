#include <iostream>
#include <chrono>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node (int value){
        this->data = value;
        this->next = NULL;
    }
};

struct LinkedList{
    Node* head = NULL;

    bool isEmpty(){
        if (this->head == NULL){
            return true;
        }
        return false;
    }


    void push(int newData){

        Node* newNode = new Node(newData);

        if (this->isEmpty()){
            this->head = newNode;
            newNode->next = NULL;

        } else {
            // Each new element will be assigned to the head of the linked list
            newNode->next = this->head;
            this->head = newNode;    

        }
    }

    int pop(){
        if (this->isEmpty()){
            cout << "Error: Stack Underflow!\n";
            return -1;

        } else {
            int toReturn = this->head->data;
            this->head = (this->head)->next;
            return toReturn;
        }
    }

    int stackTop(){
        if (!this->isEmpty()){
            return this->head->data;
        }

        cout << "Error: Stack is empty!\n";
        return -1;
    }

    void display(){

        if (this->isEmpty()){
            cout << "Error: Stack is empty!\n";
            return;
        }

        Node* currentNode = this->head;

        cout << "{ ";
        while (currentNode != NULL){
            cout << currentNode->data << ", ";
            currentNode = currentNode->next;
        }

        cout << "\b\b }\n";
    }

};

int main(){

    auto start = chrono::high_resolution_clock::now();

    LinkedList* myStack = new LinkedList;

    myStack->push(8);
    myStack->push(10);
    myStack->push(5);
    myStack->push(11);
    myStack->push(15);
    myStack->push(23);
    myStack->push(6);
    myStack->push(18);
    myStack->push(20);
    myStack->push(17);

    myStack->display(); // Should be { 8, 10, 5, 11, 15, 23, 6, 18, 20, 17 }

    for (int i = 0; i < 5; i++) {
        myStack->pop();
    }

    myStack->display(); // Should be { 8, 10, 5, 11, 15 }

    myStack->push(4);
    myStack->push(30);
    myStack->push(3);
    myStack->push(1);

    myStack->display(); // Should be { 8, 10, 5, 11, 15, 4, 30, 3, 1 }


    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Time Taken: " << duration.count() << "\n";
    
    return 0;
}