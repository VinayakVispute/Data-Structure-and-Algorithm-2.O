#include <iostream>
#include <algorithm>

using namespace std;

class Dequeue {
private:
  // Initialize your data structure.

  int size;
  int *arr;
  int front;
  int rear;

public:
  Dequeue(int n) {
    size = n;
    arr = new int[size];
    front = rear = -1;
  }
  // Pushes 'X' in the front of the deque. Returns true if it gets pushed into
  // the deque, and false otherwise.
  bool push_font(int value) {
    // Queue is  Full Condition
    if (isFull) {
      return false;
    } else {
      // First Element is Pushed
      if (isEmpty()) {
        rear = front = 0;
      } else if (front == 0 && rear != size - 1) {
        // For Circular Condition
        front = size - 1;
      } else {
        front--;
      }
      arr[front] = value;
      return true;
    }
  }

  bool push_rear(int value) {
    // Queue is Full Condition
    if (isFull) {
      return false;
    }
    // Queue is not Empty
    else {
      if (isEmpty()) {
        // First Element is Pushed
        rear = front = 0;
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

  int pop_rear() {
    // Queue is Empty
    if (isEmpty()) {
      return -1;
    } else {
      int a = arr[rear];
      if (front == rear) {
        // Single Element
        front = rear = -1;
      } else if (rear == 0) {
        // Implementation of Circular Nature;
        rear = size - 1;
      } else {
        rear--;
      }
      return a;
    }
  }

  int pop_front() {
    // Queue is Empty
    if (isEmpty()) {
      return -1;
    } else {
      int a = arr[front];
      if (front == rear) {
        // Single Element
        front = rear = -1;
      } else if (front == size - 1) {
        // Implementation of Circular Nature;
        front = 0;
      } else {
        front++;
      }
      return a;
    }
  }

  bool isEmpty() { return (rear == -1 & front == -1); }

  int getFront() {
    if (isEmpty()) {
      return -1;
    } else {
      return arr[front];
    }
  }

  int getRear() {
    if (isEmpty()) {
      return -1;
    } else {
      return arr[rear];
    }
  }

  bool isFull() {

    return ((rear == size - 1 && front == 0) ||
            (front != 0 && rear == (front - 1) % (size - 1)));
    // Because if front==0 then (front-1)<0 and negative%somenmber=0
    // So this is error we can suck :->
  }
};

int main() {}