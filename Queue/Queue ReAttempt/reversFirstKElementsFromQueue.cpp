#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

void print(queue <int> arr){
    cout<<endl;
    while(!arr.empty()){
        int topElement = arr.front();
        cout<<topElement<<" ";
        arr.pop();
    }
    cout<<endl;

}

void reverseFirstKElement(queue <int> &que, int kSize){
    stack <int> temp;
    for(int i=0;i<kSize;i++){
        int frontElement = que.front();
        temp.push(frontElement);
        que.pop();
    }

    while(!temp.empty()){
        int topElement = temp.top();
        que.push(topElement);
        temp.pop();
    }
    for(int i = 0; i< que.size()-kSize;i++ ){
        int frontElement = que.front();
        que.pop();
        que.push(frontElement);
    }
}

int main() {

  int size;
  cin >> size;

  queue<int> que;

  for (int i = 0; i < size; i++) {
    int tempElement;
    cin >> tempElement;
    que.push(tempElement);
  }

  int kSize;
  cout<<endl<<"Enter the Value of K : ";
  cin>>kSize;

  reverseFirstKElement(que, kSize);
  print(que);
}