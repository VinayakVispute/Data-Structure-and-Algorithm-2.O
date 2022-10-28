#include <iostream>
#include <algorithm>

using namespace std;

class Queue {
  int *arr;
  int n;
  int frontn;
  int rear;

public:
  Queue() {
    // Implement the Constructor
    n = 100001;
    arr = new int[n];
    frontn = -1;
    rear = -1;
  }

  /*----------------- Public Functions of Queue -----------------*/

  // Size Function is not Sure....
  int size() {
    if (rear == -1) {
      cout << "Queue is Empty" << endl;
      return 0;
    }
    if (rear == 0 && front == 0) {
      return 1;
    } else {
      return (rear - front);
    }
  }
  bool isEmpty() {
    // Implement the isEmpty() function
    if (rear == -1 && frontn == -1) {
      return true;
    } else {
      return false;
    }
  }

  void push(int value) {
    // Implement the push() function
    if (frontn == -1 && rear == -1) {
      arr[0] = value;
      frontn++;
      rear++;
      return;
    } else {
      rear++;
      arr[rear] = value;
      return;
    }
  }

  int pop() {
    // Implement the pop() function
    // Implement the pop() function
    int a;

    if (rear != -1 && (rear == frontn)) {
      a = arr[frontn];
      rear = -1;
      frontn = -1;

    } else if (rear == -1) {
      return -1;
    }

    else {
      a = arr[frontn];
      frontn++;
    }
    return a;
  }

  int front() {
    // Implement the front() function
    if (this->frontn == -1) {
      return -1;
    } else {
      return arr[this->frontn];
    }
  }
  int back() {
    if (rear == -1) {
      return -1;
    } else {
      return arr[rear];
    }
  }
};

int main() {
  queue q;
  q.push(1);
  q.backelement();
  q.frontelement();
  q.size();
  q.isEmpty();
  q.push(2);
  q.backelement();
  q.frontelement();
  q.size();
  q.isEmpty();
  q.pop();
  q.backelement();
  q.frontelement();
  q.size();
  q.isEmpty();
}