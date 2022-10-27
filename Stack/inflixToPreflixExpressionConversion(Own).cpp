#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;
//( or ) or + or - or * or / or Character

// Example : ((a-(b/c))*((a/k)-l))==  *-a/bc-/akl

string returnPreflixExpression(string str) {

  stack<char> temp;
  string ans;
  for (int i = str.length() - 1; i >= 0; i--) {
    char a = str[i];
    if (a == ')' || a == '+' || a == '-' || a == '/' || a == '*') {
      temp.push(a);

    } else if (a == '(') {
      while (temp.top() != ')') {
        char b = temp.top();
        ans.push_back(b);
        temp.pop();
      }
      temp.pop();

    } else {

      ans.push_back(a);
    }
  }

  // while (temp.empty()) {
  //   ans.push_back(temp.top());
  //   temp.pop();
  // }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {

  string str;
  cin >> str;
  string ans = returnPreflixExpression(str);
  cout << endl << ans;
}