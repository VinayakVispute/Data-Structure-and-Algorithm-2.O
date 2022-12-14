#include <iostream>
#include <algorithm>
#include <queue>

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

void queueReversal(queue<int> &arr){
    if (arr.empty()){
        return ;
    }
        int topElement = arr.front();
        arr.pop();
        queueReversal(arr);
        arr.push(topElement);
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