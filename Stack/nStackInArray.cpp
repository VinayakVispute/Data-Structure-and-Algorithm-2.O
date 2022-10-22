#include <iostream>
#include <algorithm>

using namespace std;

class NStack {
  int *arr;
  int *next;
  int *top;
  int size, n;
  int freeSpot;

public:
  // Initialize your data structure.
  NStack(int N, int S) {
    // Write your code here.
    top = new int[N];
    arr = new int[S];
    next = new int[S];
    size = S;
    n = N;

    for (int i = 0; i < S; i++) {
      if (i == S - 1) {
        next[i] = -1;
      } else {
        next[i] = i + 1;
      }
    }
    for (int i = 0; i < N; i++) {
      top[i] = -1;
    }
    freeSpot = 0;
  }

  // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the
  // stack, and false otherwise.
  bool push(int x, int m) {
    // Write your code here.
    if (freeSpot == -1) {
      return false;
    }
    int index = freeSpot;
    freeSpot = next[index];
    arr[index] = x;
    next[index] = top[m - 1];
    top[m - 1] = index;
    return true;
  }

  // Pops top element from Mth Stack. Returns -1 if the stack is empty,
  // otherwise returns the popped element.
  int pop(int m) {
    // Write your code here.
    if (top[m - 1] == -1) {
      return -1;
    }

    int index = top[m - 1];
    top[m - 1] = next[index];
    next[index] = freeSpot;
    freeSpot = index;
    return arr[index];
  }
};

int main() {
  NStack n(3, 6);
  // cout << n.push(10, 1) << endl;
  // cout << n.push(20, 1) << endl;
  // cout << n.push(30, 2) << endl;
  // cout << n.pop(1) << endl;
  // cout << n.pop(2) << endl;
}