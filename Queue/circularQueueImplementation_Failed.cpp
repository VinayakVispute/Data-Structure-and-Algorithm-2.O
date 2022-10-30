#include <iostream>
#include <algorithm>

using namespace std;

class Queue {
private:
  int *arr;
  int front;
  int rear;
  int size;

public:
  // Initialize your data structure.
  Queue(int n) {
    size = n;
    arr = new int[size];
    front = 0;
    rear = 0;
  }
  // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack,
  // and false otherwise
  bool enqueue(int value) {
    if (rear == size && front != 0) {
      arr[rear] = value;
      rear = 0;
    } else if (rear < size && (rear + 1) != front) {
      arr[rear] = value;
      rear++;
    } else {
      return false;
    }
    return true;
  }

  // Dequeues top element from queue. Returns -1 if the stack is empty,
  int dequeue() {
    if (rear == front) {
      return -1;
    } else {
      int a = arr[front];
      arr[front] = -1;
      if (front < size - 1) {
        front++;
      } else if (front == size - 1) {
        front = 0;
      } else {
        return -1;
      }
      return a;
    }
  }
};

int main() {
  Queue q(3);
  cout << q.enqueue(2) << endl;
  cout << q.enqueue(3) << endl;
  cout << q.dequeue() << endl;
  cout << q.enqueue(4) << endl;
  cout << q.enqueue(6) << endl;
  cout << q.enqueue(7) << endl;
  cout << q.dequeue() << endl;
}