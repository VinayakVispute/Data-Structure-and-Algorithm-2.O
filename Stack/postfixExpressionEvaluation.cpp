#include <iostream>
#include <stack>

using namespace std;

int sum(int a, int b, char op) {
  switch (op) {
  case '+':
    return a + b;
    break;
  case '-':
    return a - b;
    break;
  case '*':
    return a * b;
    break;
  case '/':
    return a / b;
    break;
  }
}

int prefixEvaluation(string str) {
  stack<int> temp;

  for (int i = 0; i < str.length(); i++) {
    char a = str[i];
    if (a == '+' || a == '-' || a == '*' || a == '/') {
      int op2 = temp.top();
      temp.pop();
      int op1 = temp.top();
      temp.pop();
      int soln = sum(op1, op2, a);
      temp.push(soln);

    } else {
      temp.push(int(a) - 48);
    }
  }

  return temp.top();
}

int main() {

  string str;
  cin >> str;
  cout << prefixEvaluation(str);
}