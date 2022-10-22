#include <iostream>
#include <algorithm>

using namespace std;

class NStack {
private:
  int *arr;
  int size;
  int *top;

public:
  // Initialize your data structure.
  NStack(int N, int S) {
    // Write your code here.
    size = S;
    arr = new int[size];
    top = new int[N];
    int n = S / N;
    int a = 0;
    for (int i = 0; i < size; i++) {
      arr[i] = -1;
    }
    for (int i = 0; i < N; i++) {
      top[i] = a;
      a += n;
    }
  }

  // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the
  // stack, and false otherwise.
  bool push(int x, int m) {
    // Write your code here
    int currTop = top[m - 1];

    if (arr[currTop] == -1) {
      arr[currTop] = x;
      return true;
    } else if (currTop < size - 1 && (currTop + 1) < top[m] &&
               arr[currTop + 1] == -1) {
      arr[currTop + 1] = x;
      top[m - 1]++;
      return true;
    } else if (currTop == size - 1 && (currTop + 1) == -1) {
      arr[currTop + 1] = x;
      top[m - 1]++;
      return true;
    }

    return false;
  }
  // Pops top element from Mth Stack. Returns -1 if the stack is empty,
  // otherwise returns the popped element.
  int pop(int m) {
    // Write your code here.

    int currTop = top[m - 1];
    // if first block
    bool bol = arr[currTop - 1] != -1;
    cout << endl << currTop << " " << bol << " " << arr[currTop - 1] << endl;

    if ((currTop == 0 || m == 1) && arr[currTop] != -1) {
      int a = arr[currTop];
      arr[currTop] = -1;
      top[m - 1]--;

      return a;

    } else if (arr[currTop - 1] == -1 && currTop > top[m - 1 - 1]) {
      int a = arr[currTop];
      arr[currTop] = -1;
      top[m - 1]--;

      return a;
    }

    return -1;
  }
};

int main() {
  NStack n(3, 6);
  cout << n.push(10, 1) << endl;
  cout << n.push(20, 1) << endl;
  cout << n.push(30, 2) << endl;
  cout << n.pop(1) << endl;
  cout << n.pop(2) << endl;
}