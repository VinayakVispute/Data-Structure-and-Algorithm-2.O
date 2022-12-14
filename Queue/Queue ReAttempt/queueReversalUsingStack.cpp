#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

void queueReversal(queue<int> &arr){
    stack<int> temp;
    while(!arr.empty()){
        int topElement = arr.front();
        temp.push(topElement);
        arr.pop();
    }
    while(!temp.empty()){
        int topElement = temp.top();
        arr.push(topElement);
        temp.pop();

    }

}

void print(queue <int> arr){
    cout<<endl;
    while(!arr.empty()){
        int topElement = arr.front();
        cout<<topElement<<" ";
        arr.pop();
    }
    cout<<endl;

}

int main(){
    int noOfElements;
    cin>>noOfElements;

    queue <int>arr;
    for(int i=0;i<noOfElements;i++){
        int n;
        cin>>n;
        arr.push(n);
    }
    queueReversal(arr);
    print(arr);

}