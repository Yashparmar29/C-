#include <iostream>
using namespace std;



class Stack 
{
    int size = 5;
    int top;

public:
    int arr[5];
    Stack() { top = -1; }

    void push(int x) {
        if (top >= (size - 1)) return;
        arr[++top] = x;
    }

    void pop() {
        if (top < 0) return;
        top--;
    }

    int peek() {
        if (top < 0) return -1;
        return arr[top];
    }
};
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl;
    s.pop();
    cout << "Top after one pop: " << s.peek() << endl;

    return 0;
}