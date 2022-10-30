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
    front = -1;
    rear = -1;
  }
  // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack,
  // and false otherwise
  bool enqueue(int value) {
    // Queue is Full Condition
    if ((rear == size - 1 && front == 0) || ((rear + 1) == front)) {
      // here for the condition *((rear+1)==front)* we can also use
      // (rear==(front-1)%(size-1));
      return false;
    }
    // Queue is not Empty
    else {
      if (rear == -1) {
        // First Element is Pushed
        rear = 0;
        front = 0;
      } else if (rear == size - 1 && front != 0) {
        // rear is at last andd first position is empty
        // Means to Full Fill Circular property
        rear = 0;
      } else {
        // normal Flow of the Push Operation
        rear++;
      }
      arr[rear] = value;
      return true;
    }
  }

  // Dequeues top element from queue. Returns -1 if the stack is empty,
  int dequeue() {

    if (front == -1) {
      return -1;
    } else {
      int a = arr[front];
      if (front == rear) { // single element
        front = -1;
        rear = -1;
      } else if (front == size - 1 &&
                 rear != 0) { // using circular property of queue
        front = 0;
      } else {
        front++;
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