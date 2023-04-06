// Implementation of stacks using arrays
#include <iostream>
#include <chrono>

using namespace std;

struct Stack {
    int* stackElements;
    int top;
    int size;

    Stack(){
        int arrSize = 0;
        cout << "Enter size of the array: ";
        cin >> arrSize;

        this->stackElements = new int[arrSize];
        this->size = arrSize;
        this->top = -1;
    }

    bool isFull(){
        if ((this->top + 1) == this->size){
            return true;
        }

        return false;
    }

    bool isEmpty(){
        if(this->top < 0){
            return true;
        }
        return false;
    }


    void push(int toPush){
        if (this->isFull()){
            cout << "Error: Stack Overflow!\n";
        } else {
            this->top++;
            this->stackElements[this->top] = toPush;
        }
    }

    int pop(){
        if (this->isEmpty()){
            cout << "Error: Stack Underflow!\n";
            return -1;

        } else {
            this->top--;
            return this->stackElements[(this->top + 1)];

        }
    }

    int stackTop(){
        if (!this->isEmpty()){
            return this->stackElements[this->top];

        } else {
            cout << "Error: Stack is empty!\n";
            return -1;

        }
    }

    void display(){
        if (!this->isEmpty()){
            cout << "{ ";
            for (int i = 0; i <= this->top; i++){
                cout << this->stackElements[i] << ((i == this->top) ? " " : ", ");
            }
            cout << "}\n";
        }
    }
    
};


int main(){

    Stack* myStack = new Stack();

    auto start = chrono::high_resolution_clock::now();


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