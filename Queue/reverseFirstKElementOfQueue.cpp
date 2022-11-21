#include <iostream>
#include <stack>
#include <queue>

using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {
  // add code here.
  stack<int> temp;
  int n = q.size();
  for (int i = 0; i < k; i++) {
    temp.push(q.front());
    q.pop();
  }

  while (!temp.empty()) {
    q.push(temp.top());
    temp.pop();
  }

  for (int i = 0; i < n - k; i++) {
    q.push(q.front());
    q.pop();
  }
  return q;
}
void print(queue<int> q) {
  cout << endl;
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
}

int main() {
  queue<int> q;
  int k = 3;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  print(q);
  q = modifyQueue(q, k);
  print(q);
}