#include <iostream>
#include <queue>

using namespace std;

void rev(queue<int> &q) {
  if (q.empty()) {
    return;
  }
  int a = q.front();
  q.pop();
  rev(q);
  q.push(a);
}

void print(queue<int> q) {
  cout << endl;
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
}

queue<int> reverseQueue(queue<int> q) {
  rev(q);
  return q;
}

int main() {
  queue<int> q;
  q.push(4);
  q.push(3);
  q.push(1);
  q.push(10);
  q.push(2);
  q.push(6);
  print(q);
  queue<int> ans;
  ans = reverseQueue(q);
  print(ans);
}