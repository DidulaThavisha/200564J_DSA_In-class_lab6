#include <iostream>
#include <chrono>
using namespace std;

// Define the Node struct
struct Node {
    int data;
    Node* next;
};

// Define the Stack class
class Stack {
private:
    Node* head;
    Node* top;

public:
    // Constructor
    Stack() {
        head = NULL;
        top = NULL;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return (top == NULL);
    }

    // Function to push an element onto the stack
    void push(int n) {
        Node* newNode = new Node;
        newNode->data = n;
        newNode->next = NULL;

        if (isEmpty()) {
            head = newNode;
            top = newNode;
        }
        else {
            top->next = newNode;
            top = newNode;
        }
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Error: Stack Underflow" << endl;
            return -1;
        }
        else {
            int x = top->data;
            if (top == head) {
                top = NULL;
                head = NULL;
            }
            else {
                Node* tmp = head;
                while (tmp->next != top) {
                    tmp = tmp->next;
                }
                tmp->next = NULL;
                top = tmp;
            }
            return x;
        }
    }

    // Function to display the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        }
        else {
            cout << "Stack: ";
            Node* tmp = head;
            while (tmp != NULL) {
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    double sum=0;
    for (int i=0;i<100;i++){
        Stack s;
    
        // Push operations
        auto start_push = chrono::high_resolution_clock::now();
        s.push(8);
        s.push(10);
        s.push(5);
        s.push(11);
        s.push(15);
        s.push(23);
        s.push(6);
        s.push(18);
        s.push(20);
        s.push(17);
        
    
        // Display the stack
        s.display();
    
        // Pop operations
        
        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.pop();
        
    
        // Display the stack
        s.display();
    
        // Push operations
        s.push(4);
        s.push(30);
        s.push(3);
        s.push(1);
    
        // Display the stack
        s.display();
        auto end_pop = chrono::high_resolution_clock::now();
        
        sum+=chrono::duration_cast<chrono::microseconds>(end_pop - start_push).count() ;
             
    }
    cout << "Time taken for linked list operations: " <<sum/100<< " microseconds" << endl;
    return 0;
}
