#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void print(queue<int> q) {
  cout << endl;
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
}

queue<int> reverseQueue(queue<int> q) {
  queue<int> ans;
  stack<int> temp;
  while (!q.empty()) {
    temp.push(q.front());
    q.pop();
  }
  while (!temp.empty()) {
    ans.push(temp.top());
    temp.pop();
  }
  return ans;
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