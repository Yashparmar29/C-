#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int front, rear;
    int arr[SIZE];

public:
    CircularQueue() { front = -1; rear = -1; }

    void enqueue(int x) {
        if ((rear + 1) % SIZE == front) return;
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        arr[rear] = x;
    }

    void dequeue() {
        if (front == -1) return;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    int getFront() {
        if (front == -1) return -1;
        return arr[front];
    }
};
int main() {
    CircularQueue cq;
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);

    cq.dequeue();
    cq.dequeue();

    cq.enqueue(6);
    cq.enqueue(7);

    cout << "Current Front: " << cq.getFront() << endl;

    return 0;
}