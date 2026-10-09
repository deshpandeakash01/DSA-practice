#include <iostream>
using namespace std;
struct Queue {
    int front;
    int rear;
    int size;
    int *Q;
};
bool IsEmpty(struct Queue q) {
    return q.front == q.rear;
}
bool IsFull(struct Queue q) {
    return q.rear == q.size - 1;
}
void enqueue(struct Queue *q, int x) {
    if (IsFull(*q)) {
        cout << "Queue overflow!!\n";
    } 
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}
int dequeue(struct Queue *q) {
    if (IsEmpty(*q)) {
        cout << "Queue underflow!!\n";
        return -1;
    } 
    else
    {
        q->front++;
        return q->Q[q->front];
    }
}
void display(struct Queue q) {
    if (IsEmpty(q)) {
        cout << "Queue is empty!!\n";
        return;
    }
    for (int i = q.front + 1; i <= q.rear; i++) {
        cout << q.Q[i] << " ";
    }
    cout << "\n";
}
int main() {
    struct Queue q;
    cout << "Enter the size of queue : ";
    cin >> q.size;
    q.Q = new int[q.size];
    q.front = q.rear = -1;
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(q);
    cout << "Dequeued: " << dequeue(&q) << "\n";
    display(q);
    return 0;
}
