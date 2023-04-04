#include <iostream>
#include <ctime>
using namespace std;

const int MAX_SIZE = 10;

class Stack {
private:
    int top;
    int arr[MAX_SIZE];

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        top++;
        if (top >= MAX_SIZE) {
            cout << "Stack Overflow" << endl;
            top--;
        }
        else {
            arr[top] = x;
        }
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else {
            int value = arr[top];
            top--;
            return value;
        }
    }

    void display() {
        cout << "Stack contents: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    double sum=0;
    
    for (int i=0;i<100;i++){
        Stack s;
        int start_s = clock();
    
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
    
        s.display();
    
        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.pop();
    
        s.display();
    
        s.push(4);
        s.push(30);
        s.push(3);
        s.push(1);
    
        s.display();
    
        int stop_s = clock();
        sum+=(stop_s - start_s) / double(CLOCKS_PER_SEC)*1000000  ;
    }
    cout << "Time taken for Array operations: " <<sum/100<< " microseconds" << endl;
    return 0;
}
