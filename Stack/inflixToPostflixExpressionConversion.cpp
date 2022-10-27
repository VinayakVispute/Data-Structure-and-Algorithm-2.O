#include <iostream>
#include <stack>

using namespace std;

// (a-b/c)*(a/k-l)
/*
If Operand then, print

if '(' , then push to stack

if ')' ,then pop from stack and print untill '(' is found

if operator , then pop from stack and print untill
              an operator with less precedence is found


*/

int prec(char c) {
  if (c == '^') {
    return 3;
  } else if (c == '*' || c == '/') {
    return 2;
  } else if (c == '+' || c == '-') {
    return 1;
  } else {
    return -1;
  }
}

string inflixToPostflix(string str) {
  string ans;
  stack<char> temp;
  for (int i = 0; i < str.length(); i++) {
    char a = str[i];
    if (a == '(') {

      temp.push(a);

    } else if (a == ')') {

      while (!temp.empty() && temp.top() != '(') {

        char b = temp.top();
        ans.push_back(b);
        temp.pop();
      }

      if (!temp.empty()) {
        temp.pop();
      }

    } else if (a == '+' || a == '-' || a == '/' || a == '*' || a == '^') {
      while (!temp.empty() && (prec(temp.top()) > prec(a))) {
        char b = temp.top();
        ans.push_back(b);
        temp.pop();
      }
      temp.push(a);
    } else {
      ans.push_back(a);
    }
  }
  while (!temp.empty()) {
    char a = temp.top();
    ans.push_back(a);
    temp.pop();
  }
  return ans;
}
int main() {

  string a;
  cin >> a;
  cout << inflixToPostflix(a);
}